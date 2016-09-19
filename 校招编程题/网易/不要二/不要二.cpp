/**************************************
* @author dujiong
* @date 2016.9.19
* @version V0.1
**************************************/

#include <iostream>

using namespace std;

int main(){
    int w, h, ans = 0;
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if( (i / 2 + j / 2) % 2 == 0)
                ans++;
        }
    }
    cout << ans << endl;
}
