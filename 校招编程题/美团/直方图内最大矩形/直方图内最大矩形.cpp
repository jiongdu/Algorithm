/**************************************
* @author dujiong
* @date 2016.8.3
* @version V0.1
**************************************/

class MaxInnerRec {
public:
    int countArea(vector<int> A, int n){
        int max = 0;
        vector<int> temp(n,10000);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j==i){
                    temp[i]=A[i];
                }
                temp[i]=min(temp[i],A[j]);
                max=max>(temp[i]*(j-i+1))?max:(temp[i]*(j-i+1));
            }
        }
        return max;
    }
};
