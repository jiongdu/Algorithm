/**************************************
* @author dujiong
* @date 2016.9.7
* @version V0.1
**************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int f0 = 0;
    int f1 = 1;
    int N;
    while(cin >> N){
        int temp =0;
        int diff1 = 0;
        int diff2 = 0;
        while(1){
           	temp = f0 + f1;
        	f0 = f1;
        	f1 = temp;
            if(temp < N){
                diff1 = N - temp;
            }else{
                diff2 = temp - N;
                break;
            }

        }
        int ret = std::min(diff1, diff2);
        cout << ret << endl;
    }
}

