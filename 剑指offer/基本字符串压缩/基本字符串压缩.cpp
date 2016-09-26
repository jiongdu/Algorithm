/**************************************
* @author dujiong
* @date 2016.9.26
* @version V0.1
**************************************/

class Zipper {
public:
    string zipString(string iniString) {
       	string ret;
    	int n = iniString.size();
    	int index = 0;
    	int start = 0;
    	while(index < n){
        	if(iniString[index]!=iniString[index+1]){
                ret += iniString[index] + to_string(index-start+1);
            	start = index + 1;
            	index++;
        	}else{
            	while(iniString[index]==iniString[index+1]){
               		index++;
            	}
        	}
    	}
    	if(n<=ret.size()){
        	return iniString;
    	}else{
        	return ret;
    	}
    }
};