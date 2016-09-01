/**************************************
* @author dujiong
* @date 2016.9.1
* @version V0.1
**************************************/

#include <iostream>
#include <string>

using namespace std;

void stringSet(string s){
    int temp[256]={0};
    for(int i=0;i<s.size();i++){
        temp[s[i]]++;
        if(temp[s[i]]==1){
            cout << s[i];
        }
    }
    cout << endl;
}

int main()
{
    string a;
    while(cin >> a){
        stringSet(a);
    }

    return 0;
}
