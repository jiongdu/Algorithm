/**************************************
* @author dujiong
* @date 2017.1.10
* @version V0.1
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long ip_to_num(string ip){
    vector<int> ivec;
    string temp;
    for(int i=0;i<ip.length();i++){
        if(ip[i]=='.'){
            ivec.push_back(stoi(temp));
            temp.clear();
        }else{
            temp+=ip[i];
        }
    }
    ivec.push_back(stoi(temp));

    long long res = ivec[3]+ivec[2]*256+ivec[1]*(long long)65536+ivec[0]*(long long)16777216;
    return res;
}


string num_to_ip(long long x){
    vector<int> ivec;
    long long i=16777216;
    while(x && i!=0){
        long long temp = x/i;
        ivec.push_back(temp);
        x-=temp*i;
        i=i/256;
    }
    string str;
    for(int i=0;i<ivec.size()-1;i++){
        str+=to_string(ivec[i])+".";
    }
    str+=to_string(ivec[3]);
    return str;
}

int main()
{
	long long x;
    string ip;
    
    while(cin >> ip >> x){
        long long ret = ip_to_num(ip);
        string str = num_to_ip(x);
        cout << ret << endl << str << endl;
    }
    
    return 0;
}


