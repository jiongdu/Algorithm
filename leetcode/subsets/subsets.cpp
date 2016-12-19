/**************************************
* @author dujiong
* @date 2016.12.19
* @version V0.1
**************************************/

/*
// 二进制位操作的思想
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
    	int len = S.size();
        std::sort(S.begin(), S.end());
        vector<vector<int> > res;		
        unsigned long bit = 0, bitmax=(1<<len);
        vector<int> tmp;
        while(bit < bitmax){
            tmp.clear();
            unsigned long curBit = bit;
            for(int i=0;i<len;i++){
                if(curBit&1){
                    tmp.push_back(S[i]);
                }
                curBit>>=1;
            }
            res.push_back(tmp);
            bit++;
        }
        return res;
    }
};

/*
// dfs 深度优先搜索
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<int> tmp;
        dfs(S, 0, tmp);
        return res;
    }
private:
    void dfs(vector<int>& S, int start, vector<int>& tmp){
        if(start==S.size()){
            res.push_back(tmp);
            return;
        }
        tmp.push_back(S[start]);
        dfs(S, start+1, tmp);
        tmp.pop_back();
        dfs(S, start+1, tmp);
    }
     
    vector<vector<int> > res;
};
