/**************************************
* @author dujiong
* @date 2016.8.18
* @version V0.1
**************************************/

class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        int startX = 0;
        int startY = 0;
        int endX = 0;
        int endY = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 1){
                    startX = i;
                    startY = j;
                }
                if(map[i][j] == 2){
                    endX = i;
                    endY = j;
                }
            }
        }

        int dirX = startX > endX ? -1 : 1;
        int dirY = startY > endY ? -1 : 1;

        for(int x = startX; x != endX + dirX; x += dirX){
            for(int y = startY; y != endY + dirY; y += dirY){
                if(x == startX && y == startY){
                    map[x][y] = 1;
                }else if(x == startX){
                    map[x][y] = (map[x][y] == -1) ? 0 : map[x][y-dirY];
                }else if(y == startY){
                    map[x][y] = (map[x][y] == -1) ? 0 : map[x-dirX][y];
                }else{
                    map[x][y] = (map[x][y] == -1) ? 0 : map[x-dirX][y] + map[x][y-dirY];
                }
            }
        }
        return map[endX][endY];
    }
};
