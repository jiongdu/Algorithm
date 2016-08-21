/**************************************
* @author dujiong
* @date 2016.8.21
* @version V0.1
**************************************/

class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int temp=m^n;
        int ret=0;
        while(temp!=0){
            temp=temp&(temp-1);
            ret++;
        }
        return ret;
    }
};
