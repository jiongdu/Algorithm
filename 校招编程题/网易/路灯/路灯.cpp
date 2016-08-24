/**************************************
* @author dujiong
* @date 2016.8.24
* @version V0.1
**************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double minDistance(vector<int> location, int n, int l){
    std::sort(location.begin(),location.end());
    int result[n];
    std::adjacent_difference(location.begin(),location.end(),result);
    int maxNum = 0;

    for(int i=1;i<n;i++){
        if(result[i]>maxNum){
            maxNum = result[i];
        }
    }
    double res = max(location[0],l-location[n-1]);
    res = max(res,maxNum/2.0);
    return res;
}

int main()
{
    int N,L;

    while(cin >> N >> L){
        vector<int> location(N);
        for(int i=0;i<N;i++){
            cin >> location[i];
        }
        double ret = minDistance(location,N,L);
        cout << fixed << setprecision(2) << ret << endl;
    }

    return 0;
}
