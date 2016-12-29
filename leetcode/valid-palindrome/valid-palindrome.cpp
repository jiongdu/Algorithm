/**************************************
* @author dujiong
* @date 2016.12.29
* @version V0.1
**************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        bool flag = true;
        if(len == 0) return flag;
        
        string str;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')){
                str+=s[i];
            }
        }
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        string temp(str);
        std::reverse(str.begin(), str.end());
        if(str!=temp){
            flag=false;
        }
        return flag;
    }
};
