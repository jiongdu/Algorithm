/**************************************
* @author dujiong
* @date 2017.2.13
* @version V0.1
**************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag=false;
        int rows = matrix.size();
        if(rows==0) return false;
        int columns = matrix[0].size();
        int row = 0;
        int column = columns-1;
        while(row<rows && column>=0){
            if(matrix[row][column]==target){
                flag=true;
                break;
            }else if(matrix[row][column]>target){
                column--;
            }else{
                row++;
            }
        }
        return flag;
    }
};