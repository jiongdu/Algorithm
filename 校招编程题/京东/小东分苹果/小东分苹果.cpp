/**************************************
* @author dujiong
* @date 2016.8.19
* @version V0.1
**************************************/

class Apples {
public:
    int getInitial(int n) {
        int ret=0;
     	ret = pow(n,n)-n+1;
        return ret;
    }
};
