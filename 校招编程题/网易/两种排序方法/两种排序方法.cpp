/**************************************
* @author dujiong
* @date 2016.9.7
* @version V0.1
**************************************/

#include <iostream>
#include <algorithm>

using namespace std;

bool isLexicographically(vector<string> s)
{
    vector<string> temp(s);
    std::sort(s.begin(),s.end());
    if(temp == s){
        return true;
    }
    return false;
}

bool isLength(vector<string> s)
{
    vector<int> sSize(s.size(),0);
    for(int i=0;i<s.size();i++){
        sSize[i] = s[i].length();
    }
    vector<int> temp(sSize);
    std::sort(sSize.begin(),sSize.end());
    if(sSize == temp){
        return true;
    }

    return false;
}

int main()
{
    int N;
    while(cin >> N){
        vector<string> s(N,"0");
        for(int i=0;i<N;i++){
            cin >> s[i];
        }

        if(isLength(s) && isLexicographically(s)){
            cout << "both" << endl;
        }else if(isLength(s)){
            cout << "lengths" << endl;
        }else if(isLexicographically(s)){
            cout << "lexicographically" << endl;
        }else{
            cout << "none" << endl;
        }
    }
    return 0;
}


