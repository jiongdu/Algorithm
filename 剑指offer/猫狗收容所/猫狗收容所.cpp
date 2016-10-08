/**************************************
* @author dujiong
* @date 2016.10.8
* @version V0.1
**************************************/

class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {

     	queue<int> dog,cat;
        int order=0;
        vector<int> ret;
        for(int i=0;i<ope.size();i++){
            if(ope[i][0]==1){
                if(ope[i][1]>0){
                    dog.push(order++);
                    dog.push(ope[i][1]);
                }else{
                    cat.push(order++);
                    cat.push(ope[i][1]);
                }
            }else{
                if(ope[i][1]==0){
                    int min = 0;
                    if(cat.empty() && !dog.empty()){
                        min = 1;
                    }
                    if(!cat.empty() && dog.empty()){
						min = -1;
                    }
                    if(!cat.empty() && !dog.empty()){
                        min = dog.front() > cat.front() ? -1:1;
                    }
                    if(min == 1){
                        dog.pop();
                        ret.push_back(dog.front());
                        dog.pop();
                    }
                    if(min == -1){
                        cat.pop();
                        ret.push_back(cat.front());
                        cat.pop();
                    }
                    
                }else{
                    if(ope[i][1]==1 && !dog.empty()){
                        dog.pop();
                        ret.push_back(dog.front());
                        dog.pop();
                    }
                    if(ope[i][1]==-1 && !cat.empty()){
                        cat.pop();
                        ret.push_back(cat.front());
                        cat.pop();
                    }
                }
            }
        }
        return ret;
    }
};