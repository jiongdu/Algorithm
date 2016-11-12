/**************************************
* @author dujiong
* @date 2016.11.12
* @version V0.1
**************************************/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
     
      	if(n==0) return;
        while(m>0 && n>0){
            if(A[m-1]>B[n-1]){
                A[m+n-1]=A[m-1];
                m--;
            }else{
                A[m+n-1]=B[n-1];
                n--;
            }
        }
        while(n>0){
            A[n-1]=B[n-1];
            n--;
        }
    }
};