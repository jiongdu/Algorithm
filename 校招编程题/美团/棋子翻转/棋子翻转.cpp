/**************************************
* @author dujiong
* @date 2016.8.3
* @version V0.1
**************************************/

class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {

        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<f.size();i++)
        {
            vector<int> temp(f[i]);
            for(int j=0;j<4;j++)
            {
                int tmpX=temp[0]-1+dx[j];
                int tmpY=temp[1]-1+dy[j];
                if(tmpX<=3 && tmpX>=0 && tmpY<=3 && tmpY >=0){
                    int res=A[temp[0]-1+dx[j]][temp[1]-1+dy[j]];
                    A[temp[0]-1+dx[j]][temp[1]-1+dy[j]]=!res;
                }
            }
        }
        return A;
    }
};
