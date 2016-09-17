/**************************************
* @author dujiong
* @date 2016.9.17
* @version V0.1
**************************************/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int index=0;
        for(int i=0;i<n;i++){
			if(A[i]!=elem){
                A[index++]=A[i];
            }
        }
        return index;
    }
};
