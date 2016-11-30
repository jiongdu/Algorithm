/**************************************
* @author dujiong
* @date 2016.11.30
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        do{
            ret.push_back(num);
        }while(std::next_permutation(num.begin(), num.end()));
        return ret;
    }
};