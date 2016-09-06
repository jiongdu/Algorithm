/**************************************
* @author dujiong
* @date 2016.9.6
* @version V0.1
**************************************/

class GrayCode {
public:
    vector<string> getGray(int n) {
        vector<string> gray;
        if(n==1){
            gray.push_back("0");
            gray.push_back("1");
            return gray;
        }
        vector<string> gray_last = getGray(n-1);
        for(int i=0;i<gray_last.size();i++){
			gray.push_back("0"+gray_last[i]);
        }
        for(int i=gray_last.size()-1;i>=0;i--){
            gray.push_back("1"+gray_last[i]);
        }
        return gray;
    }
};
