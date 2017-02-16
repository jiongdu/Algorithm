/**************************************
* @author dujiong
* @date 2017.2.16
* @version V0.1
**************************************/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index<=0){
            return 0;
        }
        int UglyNumberGet[index];
        UglyNumberGet[0]=1;
        int  i=1;
        int* pMultiply2 = UglyNumberGet;
        int* pMultiply3 = UglyNumberGet;
        int* pMultiply5 = UglyNumberGet;
        while(i<index){
            int min=std::min(std::min(*pMultiply2*2, *pMultiply3*3),*pMultiply5*5);
            UglyNumberGet[i]=min;
            while(*pMultiply2*2<=UglyNumberGet[i]){
                ++pMultiply2;
            }
            while(*pMultiply3*3<=UglyNumberGet[i]){
                ++pMultiply3;
            }
            while(*pMultiply5*5<=UglyNumberGet[i]){
                ++pMultiply5;
            }
            ++i;
        }
        return UglyNumberGet[i-1];
    }
};

//判断一个数是不是丑数
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;
        while(num%2==0){
            num/=2;
        }
        while(num%3==0){
            num/=3;
        }
        while(num%5==0){
            num/=5;
        }
        return (num==1)?true:false;
    }
};