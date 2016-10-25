/**************************************
* @author dujiong
* @date 2016.10.25
* @version V0.1
**************************************/

class Joseph {
public:
    int getResult(int n, int m) {

        list<int> circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        list<int>::iterator cur = circle.begin();
        while(circle.size()>1){
            for(int i=0;i<m-1;i++){
                ++cur;
                if(cur==circle.end()){
					cur=circle.begin();
                }
            }
            list<int>::iterator next = ++cur;
            if(next==circle.end()){
                next=circle.begin();
            }
            --cur;
            circle.erase(cur);
            cur=next;
        }
        return circle.front();
    }
};