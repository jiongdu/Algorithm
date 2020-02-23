local tokens_key = KEYS[1]      // 限流的标识
local timestamp_key = KEYS[2]   //令牌桶刷新的时间戳，被用来计算当前产生的令牌数

local rate = tonumber(ARGV[1])  //令牌生产的速率
local capacity = tonumber(ARGV[2])  //令牌桶的容积大小，比如最大100个，那么系统最大可承载100个并发请求
local now = tonumber(ARGV[3])   //当前时间戳
local requested = tonumber(ARGV[4]) //当前请求的令牌数量，默认是1，即当前请求


local fill_time = capacity/rate     //计算填满桶需要多长时间
local ttl = math.floor(fill_time*2) //填满桶的2倍时间作为redis中key失效的时间，避免冗余太多无用的key

//获取桶中剩余的令牌，如果桶是空的，就讲他填满
local last_tokens = tonumber(redis.call("get", tokens_key))
if last_tokens == nil then
  last_tokens = capacity
end

//获取当前令牌桶最后的刷新时间，如果为空，则设置为0
local last_refreshed = tonumber(redis.call("get", timestamp_key))
if last_refreshed == nil then
  last_refreshed = 0
end

//计算最后一次刷新到当前时间的时间差
local delta = math.max(0, now-last_refreshed)  
//计算当前令牌数量，剩余令牌数+时间差内产生的令牌 得到当前总令牌数量，和capacity取较小值
local filled_tokens = math.min(capacity, last_tokens+(delta*rate))
//根据当前令牌桶中的令牌数是否大于请求的令牌结果
local allowed = filled_tokens >= requested
//设置当前令牌数量
local new_tokens = filled_tokens
local allowed_num = 0
if allowed then
  //如果allowed为true，则将当前令牌数量充值为桶中的令牌数-请求的令牌数
  new_tokens = filled_tokens - requested
  //并且设置allowed_num标识为1
  allowed_num = 1
end
//将当前令牌数量写会到redis中，并重置令牌桶的最后刷新书剑
redis.call("setex", tokens_key, ttl, new_tokens)
redis.call("setex", timestamp_key, ttl, now)

//返回当前是否申请到了令牌，以及当前桶中剩余多少令牌
return { allowed_num, new_tokens }