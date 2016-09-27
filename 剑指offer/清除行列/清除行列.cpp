/**************************************
* @author dujiong
* @date 2016.9.27
* @version V0.1
**************************************/

class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        set<int> row,column;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(auto it = row.begin();it!=row.end();++it){
            int rows = *it;
            for(int j=0;j<n;j++){
                mat[rows][j]=0;
            }
        }

        for(auto it = column.begin();it!=column.end();++it){
			int columns = *it;
			for(int i=0;i<n;i++){
                mat[i][columns] = 0;
			}
        }
        return mat;
    }
};