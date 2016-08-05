/**************************************
* @author dujiong
* @date 2016.8.5
* @version V0.1
**************************************/

class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        int max=-65535;
        int min=A[0];
        //O(n)的时间复杂度，通过存储最小值和最大结果
        for(int i=0;i<n;i++){
                int dif=A[i]-min;
            	if(dif>max){
                    max=dif;
				}
            	if(A[i]<min){
                    min=A[i];
                }
            }
        return max;
    }
};
