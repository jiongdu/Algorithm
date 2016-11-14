/**************************************
* @author dujiong
* @date 2016.11.13
* @version V0.1
**************************************/

//空间复杂度： O(1)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
       	bool firstRow = false;
        bool firstColumn = false;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                firstColumn = true;
                break;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                firstRow = true;
                break;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firstColumn){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        if(firstRow){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
    }
};

/*
//空间复杂度仍然较高 O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        set<int> row;
        set<int> column;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(auto m:row){
            for(int j=0;j<matrix[0].size();j++){
                matrix[m][j]=0;
            }
        }
        for(auto n:column){
            for(int k=0;k<matrix.size();k++){
                matrix[k][n]=0;
            }
        }
    }
};
*/


/*
//空间复杂度较高 O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<pair<int, int> > pos;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        for(int k=0;k<pos.size();k++){
            int m = pos[k].first;
            int n = pos[k].second;
            for(int i=0;i<matrix[0].size();i++){
                matrix[m][i]=0;
            }
            for(int j=0;j<matrix.size();j++){
                matrix[j][n]=0;
            }
        }
    }
};
*/
