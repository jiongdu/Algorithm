/**************************************
* @author dujiong
* @date 2016.12.22
* @version V0.1
**************************************/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int ret[10000]={0};
        for(int i=0;i<n;i++){
            if(A[i]>0){
                ret[A[i]]=1;
            }
        }
        for(int i=1;i<10000;i++){
            if(ret[i]==0){
                return i;
            }
        }
        return 1;
    }
    
};