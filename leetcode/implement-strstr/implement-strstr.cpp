/**************************************
* @author dujiong
* @date 2017.1.3
* @version V0.1
**************************************/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	int len1 = strlen(haystack);
        int len2 = strlen(needle);
        if(len1<len2){
            return NULL;
        }
        for(int i=0;i<=len1-len2;i++){
            if(!strncmp(haystack+i, needle, len2)){
                return haystack+i;
            }
        }
        return NULL;
    }
};

/*
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        string str1(haystack);
        string str2(needle);
        
        auto pos = str1.find(str2);
        if(pos!=string::npos){
            return haystack+pos;
        }else{
            return NULL;
        }
        return NULL;
    }
};
*/