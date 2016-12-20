/**************************************
* @author dujiong
* @date 2016.12.20
* @version V0.1
**************************************/

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for(int i=0;i<n;i++){
            str+=to_string(i+1);
        }
        int j=1;
        while(j<k){
            std::next_permutation(str.begin(), str.end());
            j++;
        }
        return str;
    }
};
