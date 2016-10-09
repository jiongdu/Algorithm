/**************************************
* @author dujiong
* @date 2016.10.9
* @version V0.1
**************************************/

class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        int odd = x & (0x55555555);
        int even = x & (0xaaaaaaaa);
        int ret = (odd<<1)+(even>>1);
        return ret;
    }
};