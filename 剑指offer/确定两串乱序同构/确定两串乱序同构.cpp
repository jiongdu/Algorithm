/**************************************
* @author dujiong
* @date 2016.9.26
* @version V0.1
**************************************/

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        //第一种方法:O(nlgn)
        /*
		std::sort(stringA.begin(),stringA.end());
        std::sort(stringB.begin(),stringB.end());
        return stringA.compare(stringB)==0;
        */
		
		//第二种方法:O(n)
        /*
       	int sizeA = stringA.size();
        int sizeB = stringB.size();
        
        if(sizeA != sizeB){
            return false;
        }
        char a[256]={0};
        char b[256]={0};
        for(int i=0;i<sizeA;i++){
            a[stringA[i]]++;
            b[stringB[i]]++;
        }
        for(int i=0;i<256;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
        */
        int sizeA = stringA.size();
        int sizeB = stringB.size();
        
        if(sizeA != sizeB){
            return false;
        }
        map<char, int> ret;
        for(int i=0;i<sizeA;i++){
			ret[stringA[i]]++;
        }
        for(int j=0;j<sizeA;j++){
            if(ret.find(stringB[j])==ret.end()){
                return false;
            }else{
                ret[stringB[j]]--;
            }
        }
        for(auto it = ret.begin();it!=ret.end();it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
