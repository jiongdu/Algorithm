class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			vector<int> res;
			if(nums.size() < k) {
				return res;
			}
			priority_queue<pair<int, int>> q;
			for (int i=0; i < k;i++) {
				q.push(make_pair(nums[i], i));
			}
			if (!q.empty()) {
				res.push_back(q.top().first);
			}
			for (int i=k; i < nums.size(); i++) {
				while(!q.empty() && q.top().second <= i-k) {
					q.pop();
				}
				q.push(make_pair(nums[i], i));
				res.push_back(q.top().first);
			}
			return res;
		}
};


//双向队列deque
class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			vector<int> res;
			deque<int> q;
			for (int i=0; i<nums.size(); i++) {
				if (!q.empty() && q.front() == i-k) q.pop_front();
				while(!q.empty() && nums[q.back()]<nums[i]) {
					q.pop_back();
				}
				q.push_back(i);
				if (i>=k-1) {
					res.push_back(nums[q.front()]);
				}
			}
			return res;			
		}
};