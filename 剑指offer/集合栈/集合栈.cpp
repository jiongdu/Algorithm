/**************************************
* @author dujiong
* @date 2016.10.8
* @version V0.1
**************************************/

class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
		
        vector<int> temp;
        vector<vector<int> > ret;
        for(int i=0;i<ope.size();++i){
            if(ope[i][0]==1){
                if(temp.size()==size){
                    ret.push_back(temp);
                    temp.clear();
                }
                temp.push_back(ope[i][1]);
            }
            else if(ope[i][0]==2){
                if(temp.size()!=0){
                    temp.pop_back();
                }else if(ret.size()!=0){
                    temp=ret[ret.size()-1];
                    temp.pop_back();
                    ret.pop_back();
                }
            }
        }
        if(temp.size()!=0){
            ret.push_back(temp);
        }
        return ret;
    }
};