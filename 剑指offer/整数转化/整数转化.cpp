/**************************************
* @author dujiong
* @date 2016.10.9
* @version V0.1
**************************************/

class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        int x = A ^ B;
        int ret = 0;
        for(ret=0;x;++ret){
            x &= (x-1);
        }
        return ret;
    }
};