/**************************************
* @author dujiong
* @date 2016.11.28
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        permuteHelp(ret, num, 0);
        
        return ret;
    }
private:
    void permuteHelp(vector<vector<int> >& ret, vector<int> temp, int start){
        int end=temp.size()-1;
        if(start == end){
            ret.push_back(temp);
            return;
        }else{
            for(int j=start; j<=end; j++){
                std::swap(temp[start], temp[j]);
                permuteHelp(ret, temp, start+1);
                std::swap(temp[start], temp[j]);
            }
        }
    }
};

//运用STL算法求解
/*
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        do{
            ret.push_back(num);
        }while(std::next_permutation(num.begin(), num.end()));
        return ret;
    }
};
*/