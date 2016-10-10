/**************************************
* @author dujiong
* @date 2016.10.9
* @version V0.1
**************************************/

class Max {
public:
    int getMax(int a, int b) {

        b = a - b;      
        a -= b&(b>>31);	
        return a;
    }
};