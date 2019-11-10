class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash;
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int> > large;

        int i = 0; 
        while(i < k) {   
            small.push(nums[i++]);
        }
        for (int count = k/2; count > 0; count--) {
            large.push(small.top());
            small.pop();
        }
        while(true) {
            if (k % 2) {
                medians.push_back(small.top());
            } else {
                medians.push_back((double)(small.top() + large.top()) / 2);
            }
            if (i == nums.size()) {
                break;
            }
            int m = nums[i-k], n = nums[i++], balance = 0;
            if (m <= small.top()) {
                --balance;
                if (m == small.top()) {
                    small.pop();
                } else {
                    hash[m]++;
                }
            } else {
                ++balance;
                if (m == large.top()) {
                    large.pop();
                } else {
                    hash[m]++;
                }
            }
            if (!small.empty() && n <= small.top()) {
                balance++;
                small.push(n);
            } else {
                balance--;
                large.push(n);
            }
            if (balance < 0) {
                small.push(large.top());
                large.pop();
            } else if (balance > 0) {
                large.push(small.top());
                small.pop();
            }
            while(!small.empty() && hash[small.top()]) {
                --hash[small.top()];
                small.pop();
            }
            while(!large.empty() && hash[large.top()]) {
                --hash[large.top()];
                large.pop();
            } 
        }
        return medians;
    }
};