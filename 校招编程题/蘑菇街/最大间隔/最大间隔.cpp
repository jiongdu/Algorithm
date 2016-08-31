/**************************************
* @author dujiong
* @date 2016.8.31
* @version V0.1
**************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int n;
int a[maxn];

int main()
{
    int ret[maxn];
    while(cin >> n){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        adjacent_difference(a,a+n,ret);
        int num = *max_element(ret,ret+n);
        for(int i=1;i<n-1;i++){
            num = std::max(ret[i]+ret[i+1],num);
        }
        adjacent_difference(a,a+n-1,ret);
        std::sort(ret,ret+n-1);
        num = std::min(num,ret[n-2]);
        cout << num << endl;
    }
    return 0;
}
