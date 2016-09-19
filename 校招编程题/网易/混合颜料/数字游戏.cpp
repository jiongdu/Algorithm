/**************************************
* @author dujiong
* @date 2016.9.19
* @version V0.1
**************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getHighBit(int num)
{
    int highbit = 0;
    while(num){
        num >>= 1;
        highbit++;
    }
    return highbit;
}

int main()
{
    int n;
    while(cin >> n){
        int res=0;
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            cin >> colors[i];
        }

        std::sort(colors.begin(),colors.end());

        int endValue = n-1;
        int cmpValue = endValue - 1;

        while(colors.size()>2){
            if(getHighBit(colors[endValue])==getHighBit(colors[cmpValue])){
                int temp = colors[endValue]^colors[cmpValue];
                if(std::find(colors.begin(),colors.end(),temp)==colors.end()){
                    colors.push_back(temp);
                    std::sort(colors.begin(),colors.end());
                    endValue++;
                    cmpValue++;
                }
            }else{
                res++;
            }
            colors.pop_back();
            endValue=cmpValue;
            cmpValue--;
        }
        cout << res+2 << endl;
    }
    return 0;
}
