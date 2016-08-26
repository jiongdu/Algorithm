/**************************************
* @author dujiong
* @date 2016.8.26
* @version V0.1
**************************************/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Course{
    int score;
    int cost;
};

bool compareCourse(Course a, Course b){
    return a.cost < b.cost;
}

int main()
{
    ll N,R,AVG;
    ll totalScore;
    ll sumScore;
    ll ret;
    while(cin >> N >> R >> AVG){
        totalScore = 0;
        ret = 0;
        sumScore = 0;
        Course course[N+1];
        for(int i=0;i<N;i++){
            cin >> course[i].score >> course[i].cost;
            totalScore += course[i].score;
        }
        std::sort(course,course+N,compareCourse);
        sumScore = AVG*N;
        for(int i=0;i<N;i++){
            if(totalScore >= sumScore)
                break;
            if(sumScore-totalScore > R-course[i].score){
                ret += course[i].cost * (R-course[i].score);
            }
            else{
                ret += course[i].cost*(sumScore-totalScore);
            }
            totalScore += (R-course[i].score);
        }
        cout << ret << endl;
    }
    return 0;
}

