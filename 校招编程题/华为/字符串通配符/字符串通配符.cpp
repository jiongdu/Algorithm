/**************************************
* @author dujiong
* @date 2016.12.9
* @version V0.1
**************************************/

#include<string>
#include<iostream>
#include<vector>

using namespace std;

int match_string(string str1, string str2){
    int row = str1.length();      //行
    int column = str2.length();   //列
    vector<vector<int> > dp(row+1, vector<int>(column+1, 0));
    dp[0][0]=1;
    for(int i=1;i<=row;i++){
        char ch = str1[i-1];
        dp[i][0] = dp[i-1][0]&&(ch=='*');   //当*不出现在匹配表达式头的时候，第一列都为false
        for(int j=1;j<=column;j++){
            char ch2 = str2[j-1];
            if(ch == '*'){
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }else{
                dp[i][j]=dp[i-1][j-1]&&(ch=='?'||ch2==ch);
            }
        }
    }
    return dp[row][column];
}
 
int main()
{
    string str1,str2;
    while(cin >> str1 >> str2)
    {
       int rst =  match_string(str1,str2);
       if(rst==1)
           cout << "true" << endl;
        else
           cout << "false" << endl;
    }
}
