/**************************************
* @author dujiong
* @date 2016.9.27
* @version V0.1
**************************************/

class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        int temp;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                temp = mat[i][j];
                mat[i][j]=mat[n-1-j][i];
                mat[n-1-j][i]=mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1]=mat[j][n-i-1];
                mat[j][n-i-1]=temp;
            }
        }
        return mat;
    }
};