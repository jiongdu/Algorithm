/**************************************
* @author dujiong
* @date 2016.12.20
* @version V0.1
**************************************/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
     	 stringstream ss(s);
         string str;
         while(ss >> str);
         return str.length();
    }
};
