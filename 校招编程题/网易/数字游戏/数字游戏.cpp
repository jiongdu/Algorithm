/**************************************
* @author dujiong
* @date 2016.9.19
* @version V0.1
**************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int miss=0;
        std::sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]>miss+1) break;
            miss+=a[i];
        }
        cout << miss+1 << endl;
    }

}
