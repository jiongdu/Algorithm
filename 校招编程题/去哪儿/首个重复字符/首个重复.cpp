/**************************************
* @author dujiong
* @date 2016.7.22
* @version V0.1
**************************************/

class FirstRepeat {
public:
    char findFirstRepeat(string A, int n){
        map<char,int> repeatString;
        for(int i=0;i<n;++i){
            repeatString[A[i]]++;
            if(repeatString[A[i]]==2){
                return A[i];
            }
        }
        return -1;
    }
};
