/**************************************
* @author dujiong
* @date 2016.10.17
* @version V0.1
**************************************/

class LCA {
public:
    int getLCA(int a, int b) {

        while(a!=b){
            if(a>b){
                a/=2;
            }else{
                b/=2;
            }
        }
        return a;
    }
};