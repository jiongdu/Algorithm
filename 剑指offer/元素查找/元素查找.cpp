/**************************************
* @author dujiong
* @date 2016.10.21
* @version V0.1
**************************************/

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {

        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low+high)/2;
            if(A[mid]==x) return mid;
            if(A[mid]<x){
                if(x>A[high] && A[mid]<A[high]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if(A[mid]>x){
                if(A[mid]>A[low] && A[low]>x){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};