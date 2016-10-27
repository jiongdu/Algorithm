/**************************************
* @author dujiong
* @date 2016.10.27
* @version V0.1
**************************************/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		char *pstr = (char*)malloc(sizeof(char)*length*3);
        int j=0;
        for(int i=0;i<length;i++){
            if(str[i]==' '){
                pstr[j]='%';
                pstr[j+1]='2';
                pstr[j+2]='0';
                j+=3;
            }else{
                pstr[j++]=str[i];
            }
        }
        for(int i=0;i<j;i++){
            str[i]=pstr[i];
        }
        free(pstr);      
	}
};