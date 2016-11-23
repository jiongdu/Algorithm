/**************************************
* @author dujiong
* @date 2016.11.23
* @version V0.1
**************************************/

class Solution {
public:
    int search(int A[], int n, int target) {

        int left=0,right=n-1;
        while(left<=right){
            //int mid=(left+right)/2;  防止溢出
            int mid=left+(right-left)/2;
            if(A[mid]==target){
                return mid;
            }
            //关键在于 整个旋转数组分为两部分之后，一定有一部分有序
            if(A[left]<=A[mid]){
                if(A[left]<=target&&target<A[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(A[mid]<target&&target<=A[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};


/*
//遍历 O(n)
class Solution {
public:
    int search(int A[], int n, int target) {
        for(int i=0;i<n;i++){
            if(A[i]==target){
                return i;
            }
        }
        return -1;
	}
}
*/