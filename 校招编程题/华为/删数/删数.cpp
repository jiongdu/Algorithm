/**************************************
* @author dujiong
* @date 2016.9.2
* @version V0.1
**************************************/

#include <iostream>
#include <queue>

using namespace std;

int deleteNum(int n){
    queue<int> que;
    for(int i=0;i<n;i++){
        que.push(i);
    }
    int count=0;
    while(que.size()!=1){
        if(count!=2){
            int a=que.front();
            que.pop();
            que.push(a);
            count++;
        }else{
            que.pop();
            count=0;
        }
    }
    return que.front();
}

int main()
{
    int N;
    while(cin >> N){
        int ret = deleteNum(N);
        cout << ret << endl;
    }
}
