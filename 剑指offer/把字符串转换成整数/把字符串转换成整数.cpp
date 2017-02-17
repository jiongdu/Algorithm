/**************************************
* @author dujiong
* @date 2017.2.17
* @version V0.1
**************************************/

class Solution {
public:
    int StrToInt(string str) {
        if (str.size() < 1)
            return 0;
        int res = 0, i = 0, sign = 1;
        if (str[0] == '+' || str[0] == '-') {
            i++;
            if (str[0] == '-')
                sign = -1;
        }
        for (; i < str.size(); i++) {
            if (str[i] > '9' || str[i] < '0')
                return 0;
            res *= 10;
            res += str[i] - '0';
        }
 
        return sign * res;
    }
};


class Solution {
public:
    int StrToInt(string str) {
        int len=str.length();
        //return charToInt(str.c_str(), len);
        return charToInt(&str[0], len);
    }
    int charToInt(const char* str, int len){
        if (len < 1)
            return 0;
        int res = 0, i = 0, sign = 1;
        if (str[0] == '+' || str[0] == '-') {
            i++;
            if (str[0] == '-')
                sign = -1;
        }
        for (; i < len; i++) {
            if (str[i] > '9' || str[i] < '0')
                return 0;
            res *= 10;
            res += str[i] - '0';
        }
 
        return sign * res;
    }
};