/**************************************
* @author dujiong
* @date 2016.12.9
* @version V0.1
**************************************/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool myfunction(const pair<char, int>& ite1,const pair<char, int>& ite2){
    if(ite1.second != ite2.second){
        return ite1.second>ite2.second;
    }else{
        return ite1.first<ite2.first;
    }
}

int main()
{
	string str;
    while(getline(cin, str)){
        map<char, int> ret;

        for(int i=0;i<str.size();i++){
            if((str[i]>='a' && str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9')||str[i]==' '){
                if(ret.find(str[i])==ret.end()){
                    ret.insert(make_pair(str[i], 1));
                }else{
                    ret[str[i]]++;
                }
            }
        }
        vector<pair<char, int> > mvec(ret.begin(), ret.end());

        std::sort(mvec.begin(), mvec.end(), myfunction);

        for(auto n:mvec){
            cout << n.first;
        }
        cout << endl;
    }
    return 0;
}
