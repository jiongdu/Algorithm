/**************************************
* @author dujiong
* @date 2016.12.7
* @version V0.1
**************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long num;
    while(cin >> num){
        for(int i=2;i<=num;i++){
            while(num%i==0){
                cout << i << " ";
                num/=i;
            }
        }
    }
    return 0;
}