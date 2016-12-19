/**************************************
* @author dujiong
* @date 2016.12.19
* @version V0.1
**************************************/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int n = s1.length();
        if(n!=s2.size()) return false;
        
        bool f[n+1][n][n]; 					//表示长度为n,起点为s1[i]和s2[j]两个字符串是否互为scramble
        std::fill_n(&f[0][0][0], (n+1)*n*n, false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                f[1][i][j]=s1[i]==s2[j];
            }
        }
        
        for(int len=1;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                for(int j=0;j+len<=n;j++){
                    for(int k=0;k<len;k++){
						if ((f[k][i][j] && f[len - k][i + k][j + k]) ||
                            (f[k][i][j + len - k] && f[len - k][i + k][j])){
                            f[len][i][j]=true;
                            break;
                        }
                    }
                }
            }
        }
        return f[n][0][0];
    }
};
