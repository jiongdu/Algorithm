/**************************************
* @author dujiong
* @date 2016.9.7
* @version V0.1
**************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isHuiwen(string s)
{
    string temp(s);
    reverse(s.begin(), s.end());
    if(s == temp){
        return true;
    }
    return false;
}

int main()
{
    string a,b;
    int ret=0;
    while(cin >> a >> b){
        string temp;

        for(int i=0;i<=a.size();i++){
            temp = a.substr(0,i)+b+a.substr(i,a.size());
            if(isHuiwen(temp)){
                ret++;
            }
        }
        cout << ret << endl;
    }

    return 0;
}

