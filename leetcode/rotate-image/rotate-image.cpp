/**************************************
* @author dujiong
* @date 2016.11.24
* @version V0.1
**************************************/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
       int temp;
       int n=matrix.size(); 
       for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                temp = matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};