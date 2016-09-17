/**************************************
* @author dujiong
* @date 2016.9.17
* @version V0.1
**************************************/

class Printer {
public:
    vector<int> arrayPrint(vector<vector<int> > arr, int n) {

		int length = n*n;
        vector<int> res(length);
        int k=0;
		for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                res[k++]=arr[j][n-i+j];
            }
        }
     	for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++){
                res[k++]=arr[n-i+j][j];
            }
        }
        return res;
    }
};
