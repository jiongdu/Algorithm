/**************************************
* @author dujiong
* @date 2016.11.13
* @version V0.1
**************************************/

class Solution {
public:
    int sqrt(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        int begin=0, end=n/2+1;
        while(begin<end-1){
            int middle=(begin+end)/2;
            if(middle>n/middle){
                end=middle;
            }
            else if(middle<n/middle){
                begin=middle;
            }
            else{
                return middle;
            }
        }
        return begin;
    }
};

/*
// error
// 原因是x*x可能溢出，left,right,n改为long long即可
class Solution {
public:
    int sqrt(int x) {
        if(x==0){
            return 0;
        }
        if(x==1 || x==2){
            return 1;
        }
        int left = 0;
        int right = x/2+1;

        while(left<right-1){
        	int n=(left+right)/2;
            if(n*n==x){
                return n;
            }else if(n*n>x){	//...
                right = n;
            }else if(n*n<x){	//...
                left = n;
            }
        }
        return left;
    }
};
*/