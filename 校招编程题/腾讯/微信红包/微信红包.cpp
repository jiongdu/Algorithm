/**************************************
* @author dujiong
* @date 2016.9.2
* @version V0.1
**************************************/

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        map<int, int> valueMap;
        for(int i=0;i<gifts.size();i++){
            valueMap[gifts[i]]++;
        }
        for(auto ite=valueMap.begin();ite!=valueMap.end();ite++){
            if(ite->second > n/2){
				return ite->first;
            }
        }
        return 0;
    }
};
