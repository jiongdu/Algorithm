/**************************************
* @author dujiong
* @date 2016.8.31
* @version V0.1
**************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isWen(string s)
{
    string res(s);
    std::reverse(s.begin(), s.end());
    if(s == res){
        return true;
    }
    return false;
}

bool isHuiWen(string s)
{
    int n=s.size();
    string temp;
    for(int i=0;i<n;i++){
        temp = s.substr(0,i)+s.substr(i+1,n);
        if(isWen(temp)){
            return true;
        }
    }
    return false;
}

int main()
{
    string a;
    while(cin >> a){

        if(isHuiWen(a)){
        cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

