/**************************************
* @author dujiong
* @date 2016.8.5
* @version V0.1
**************************************/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int W,N;
    double x,Y;
    while(cin >> W >> Y >> x >> N){
        for(int i=1;i<=N;i++){
            Y = (1-x)*(Y+1)+21*x;
        }
        cout << ceil(Y) << endl;
        //cout <<(int)ceil(Y) endl;
    }
    return 0;
}
