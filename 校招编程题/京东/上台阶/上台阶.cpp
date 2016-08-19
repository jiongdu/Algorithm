/**************************************
* @author dujiong
* @date 2016.8.19
* @version V0.1
**************************************/

class GoUpstairs {
public:
    int countWays(int n) {
        vector<int> ret(n+1,0);
        ret[0]=ret[1]=0;
        ret[2]=1;
        ret[3]=2;
        for(int i=4;i<=n;i++){
            ret[i] = (ret[i-1]+ret[i-2])%1000000007;
        }
        return ret[n];
    }
};
