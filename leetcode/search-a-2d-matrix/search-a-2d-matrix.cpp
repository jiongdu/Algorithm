/**************************************
* @author dujiong
* @date 2016.11.29
* @version V0.1
**************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int n=matrix.size();
        int m=matrix[0].size();
      
        int index;
		for(int i=0;i<n;i++){
            index = std::lower_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin();
            
            if(index<m && matrix[i][index]==target){
                return true;
            } 
                
        }
        return false;
    }
};