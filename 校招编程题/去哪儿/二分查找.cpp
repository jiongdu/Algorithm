/**************************************
* @author dujiong
* @date 2016.7.22
* @version V0.1
**************************************/

class BinarySearch{
public:
    int getPos(vector<int> A, int n, int val){
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(A[mid]==val){
                int i=mid-1;
                if(A[i]!=val){
                    return mid;
                }else{
                    for(;i>=0;i--){
                        if(A[i]!=val) break;
                    }
                    return i+1;
                }
            }else if(A[mid]<val){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};
