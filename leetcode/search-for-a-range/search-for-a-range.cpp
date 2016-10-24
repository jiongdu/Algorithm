/**************************************
* @author dujiong
* @date 2016.10.24
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        int mid;
        vector<int> ret{-1,-1}; 
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target){
                int i=mid;
                int j=mid;
                
                while(i>=0 && A[i]==target){
                    i--;
                }
                while(j<n && A[j]==target){
                    j++;
                }
                ret[0]=++i;
                ret[1]=--j;
                break;
            }else if(A[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ret;
    }
};