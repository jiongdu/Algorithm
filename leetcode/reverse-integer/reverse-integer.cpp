/**************************************
* @author dujiong
* @date 2016.11.24
* @version V0.1
**************************************/

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN){
            return 0;
        }
        int num=abs(x);
        long ret(0);
        while(num>0){
            //翻转
            ret = ret*10 + num%10;
            if(ret>INT_MAX) return 0;
            num = num/10;
        }
        return x>0 ? ret:-ret;
    }
};