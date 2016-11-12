/**************************************
* @author dujiong
* @date 2016.11.12
* @version V0.1
**************************************/

class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0;
        int right = n-1;
        int i=0;
        while(i<=right){
            if(A[i]==0){
                std::swap(A[i++],A[left++]);
            }else if(A[i]==1){
                i++;
            }else{
                std::swap(A[i],A[right--]);
            }
        }
    }
};

/*
//two-pass
class Solution {
public:
    void sortColors(int A[], int n) {
        int a[3]={0};
        for(int i=0;i<n;i++){
            a[A[i]]++;
        }
        for(int i=0;i<a[0];i++){
            A[i]=0;
        }
        for(int j=a[0];j<a[0]+a[1];j++){
            A[j]=1;
        }
        for(int k=a[0]+a[1];k<n;k++){
            A[k]=2;
        }
    }
};
*/