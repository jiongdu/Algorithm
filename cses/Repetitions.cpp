#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cur = 1, res = 0;
    for (int i =1; i < str.length(); i++) {
        if (str[i] != str[i-1]) {       
            res = std::max(res, cur);
            cur = 0;
        } 
        cur ++;
        
    }
    res = std::max(res, cur);
    cout << res;
    return 0;
}

