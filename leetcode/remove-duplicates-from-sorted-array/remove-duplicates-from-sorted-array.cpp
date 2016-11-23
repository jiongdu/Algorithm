/**************************************
* @author dujiong
* @date 2016.11.23
* @version V0.1
**************************************/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int count = 1;
        for(int i=1;i<n;i++){
            if(A[i]!=A[i-1]){
                A[count++]=A[i];		
            }
        }
        return count;
    }
};
