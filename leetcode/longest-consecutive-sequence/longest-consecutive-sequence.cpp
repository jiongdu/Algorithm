/**************************************
* @author dujiong
* @date 2016.11.22
* @version V0.1
**************************************/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash(num.begin(), num.end());
        
        int ret = 0;
        for(auto n : num){
            if(hash.find(n)==hash.end()) continue;
            hash.erase(n);
            int prev = n-1, post = n+1;
            while(hash.find(prev)!=hash.end()){
                hash.erase(prev--);
            }
            while(hash.find(post)!=hash.end()){
                hash.erase(post++);
            }
            ret = max(ret, post-prev-1);
        }
        return ret;
    }
};