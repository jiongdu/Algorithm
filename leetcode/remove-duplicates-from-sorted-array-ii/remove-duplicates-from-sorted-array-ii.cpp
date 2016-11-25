/**************************************
* @author dujiong
* @date 2016.11.25
* @version V0.1
**************************************/

class Solution {
public:
    int removeDuplicates(int A[], int n) {

        if(n<=2){
            return n;
        }
        int count = 0;
        for(int i=0;i<n-2;i++){
            if(A[i]==A[i+1] && A[i]==A[i+2])
                continue;
            A[count++]=A[i];
        }
        A[count++]=A[n-2];
        A[count++]=A[n-1];
        return count;
    }
};


/*

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2){
            return n;
        }
        int count=2;
        for(int i=2;i<n;i++){
            if(A[i]!=A[count-2]){
                A[count++]=A[i];
            }
        }
        return count;
    }
};

*/