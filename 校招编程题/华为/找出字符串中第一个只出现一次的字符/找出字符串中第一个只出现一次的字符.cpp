/**************************************
* @author dujiong
* @date 2016.12.13
* @version V0.1
**************************************/

#include <iostream>
 
using namespace std;
 
int main()
{
    string str;
    while(cin >> str){
        char a[256]={0};
        for(int i=0;i<str.size();i++){
            a[str[i]-'a']++;
        }
        int i = 0;
        for( i=0;i<str.size();i++){
            if(a[str[i]-'a']==1){
                cout << str[i] << endl;
                break;
            }
        }
        if(i==str.size()){
            cout << -1 << endl;
        }
    }
    return 0;
}