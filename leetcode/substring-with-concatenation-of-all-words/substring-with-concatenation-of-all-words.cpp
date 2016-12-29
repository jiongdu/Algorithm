/**************************************
* @author dujiong
* @date 2016.12.29
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
      	int lenS = S.length();
        int lenL = L.size();
        if(lenL==0 || lenS==0) return res;
        
        int charLen = L[0].length();
        unordered_map<string, int> map;
        unordered_map<string, int> has;
        
        for(int i=0;i<lenL;i++) map[L[i]]+=1;
        
        for(int i=0;i<=lenS-charLen*lenL;i++){
            string tmp = S.substr(i, charLen*lenL);
            int tmpLens = tmp.length();
            bool isR = true;
            for(int j=0;j<tmpLens;j+=charLen){
                string tmpS = tmp.substr(j, charLen);
                has[tmpS]+=1;
                if(has[tmpS]>map[tmpS]){
                    isR = false;
                    break;
                }
            }
            has.clear();
            if(isR) res.push_back(i);
            else continue;
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};
