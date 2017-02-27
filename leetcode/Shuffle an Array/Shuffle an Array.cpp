/**************************************
* @author dujiong
* @date 2017.2.27
* @version V0.1
**************************************/

class Solution {
public:
    Solution(vector<int> nums) : nums_(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums_);
        for(int i=0;i<res.size();++i){
            int t=rand()%res.size();
            std::swap(res[i],res[t]);
        }
        return res;
    }
private:
    vector<int> nums_;    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */