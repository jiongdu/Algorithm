/**************************************
* @author dujiong
* @date 2016.9.27
* @version V0.1
**************************************/

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
       	if(s1.size()!=s2.size()){
            return false;
        }
        int n = s1.size();
        int i = 0;
        string temp;
        for(;i<n;i++){
            if(s1[i]==s2[0]){
                temp = s1.substr(i,n-i)+s1.substr(0,i);
                if(temp == s2){
                    return true;
                }
            }
        }
        return false;
    }
};