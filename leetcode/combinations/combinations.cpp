/**************************************
* @author dujiong
* @date 2016.12.2
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> temp;
        backtracing(n, k, 1, temp);
        return ret;
    }
private:
    
    void backtracing(int n, int k, int start, vector<int>& temp){
        if(k<0){
            return;
        }else if(k==0){
            ret.push_back(temp);
        }else{
			for(int i=start; i<=n; i++){
                temp.push_back(i);
                backtracing(n, k-1, i+1, temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int> > ret;
};
