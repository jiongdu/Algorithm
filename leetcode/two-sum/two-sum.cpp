/**************************************
* @author dujiong
* @date 2016.10.21
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> imap;
        vector<int> ret;
        imap[numbers[0]]=0;
        for(int i=1;i<numbers.size();i++){
         	auto ite = imap.find(target-numbers[i]);
            if(ite!=imap.end()){
				ret.push_back(ite->second+1);
                ret.push_back(i+1);
                break;
            }else{
                imap[numbers[i]]=i;
            }
           
        }
        return ret;
    }
};