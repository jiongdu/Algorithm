/**************************************
* @author dujiong
* @date 2016.9.19
* @version V0.1
**************************************/

#include <iostream>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

const int MOD = 1000000007;

long leastPowerTimes(long x){
    map<long, int> visit;
    queue<int> que;
    que.push(x);
    visit[x]=1;

    long xx = 1;
    while(!que.empty()){
        x=que.front();
        que.pop();

        if(visit[x]>100000){
            return -1;
        }

        if(x == 0){
            break;
        }

        xx = ((x<<2)+3) % MOD;
        if(visit.find(xx)==visit.end()){
            que.push(xx);
            visit[xx] = visit[x] + 1;
        }
        xx = ((x<<3)+7) % MOD;
        if(visit.find(xx)==visit.end()){
            que.push(xx);
            visit[xx] = visit[x] + 1;
        }
    }
    return visit[0]-1;
}

int main()
{
    long N;
    while(cin >> N){
        long num = leastPowerTimes(N);
        cout << num << endl;
    }
}
