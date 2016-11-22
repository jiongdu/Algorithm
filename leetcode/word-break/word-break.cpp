/**************************************
* @author dujiong
* @date 2016.11.22
* @version V0.1
**************************************/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
       	int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0]=true;
        for(int i=1;i<=len;i++){
			for(int j=0;j<i;j++){
                if(dp[j] && dict.find(s.substr(j, i-j))!=dict.end()){		//j相当于放置隔板的位置
					dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];
    }
};