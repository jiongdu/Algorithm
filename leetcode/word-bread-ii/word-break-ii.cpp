/**************************************
* @author dujiong
* @date 2016.11.22
* @version V0.1
**************************************/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0]=true;
        for(int i=1;i<=len;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && dict.find(s.substr(j, i-j))!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        vector<string> res;
        if(dp[len]==false){
            return res;
        }
        res = findString(s, dict, dp);
        return res;
        
    }
    
private:
    vector<string> findString(string s, unordered_set<string> &dict, vector<bool> dp){
        int len = s.length();
        vector<string> res, temp;
        for(int i=len-1;i>=0;i--){
            if(dict.find(s.substr(i, len-i))!=dict.end() && dp[i]==true){
                if(i==0){
                    res.push_back(s);		
                }else{
                    temp = findString(s.substr(0, i), dict, dp);		//递归
                    for(int k=0;k<temp.size();k++){
						res.push_back(temp[k]+" "+s.substr(i, len-i));
                    }
                }
            }
        }
        return res;
    }
};