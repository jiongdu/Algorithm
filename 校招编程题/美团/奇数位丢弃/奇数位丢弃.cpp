/**************************************
* @author dujiong
* @date 2016.8.29
* @version V0.1
**************************************/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
     int n;
     while(cin >> n){
        list<int> a;
        for(int i=0;i<=n;i++){
            a.push_back(i);
        }

        while(a.size()!=1){
            for(auto ite = a.begin(); ite!=a.end() && a.size()!=1;){
                ite = a.erase(ite);
                ite++;
            }

        }
        cout << a.front() << endl;
     }
    return 0;
}
