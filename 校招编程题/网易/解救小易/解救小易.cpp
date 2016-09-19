/**************************************
* @author dujiong
* @date 2016.9.19
* @version V0.1
**************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getFootNum(int n, int x[], int y[])
{
    int x_=1;
    int y_=1;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        num[i]=x[i]-x_+y[i]-y_;
    }
    return *min_element(num.begin(),num.end());
}

int main()
{
    int n;
    while(cin >>n){
        int x[n],y[n];
        for(int i=0;i<n;i++){
            cin >> x[i];
        }
        for(int j=0;j<n;j++){
            cin >> y[j];
        }
        int ret = getFootNum(n,x,y);
        cout << ret << endl;
    }
}
