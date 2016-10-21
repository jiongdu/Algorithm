/**************************************
* @author dujiong
* @date 2016.10.21
* @version V0.1
**************************************/

class Permutation {
public:
    vector<string> getPermutation(string A) {
		
        std::sort(A.begin(),A.end());
        vector<string> ret;
        //do{
        //    ret.push_back(A);
        //}while(next_permutation(A.begin(),A.end()));  //处理相同元素时除了问题
        //getPermutation(ret, A, 0);
        getPermutation(ret, A, 0, A.size()-1);
        std::sort(ret.begin(), ret.end(), greater<string>());
        return ret;
    }
private:
    void getPermutation(vector<string>& ret, string A, int start, int end){
        if(start == end){
            ret.push_back(A);
        }else{
            for(int j=start; j<=end; j++){
                std::swap(A[start], A[j]);
                getPermutation(ret, A, start+1, end);
                std::swap(A[start], A[j]);
            }
             
        }
    }
};