/**************************************
* @author dujiong
* @date 2017.2.16
* @version V0.1
**************************************/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0) return 0;
        int ret=numbers[0];
        int times=1;
        for(int i=1;i<numbers.size();i++){
            if(times==0){
                ret=numbers[i];
                times=1;
            }else if(numbers[i]==ret){
                times++;
            }else{
                times--;
            }
        }
        int result = std::count(numbers.begin(), numbers.end(), ret);
        if(result*2>numbers.size()){
            return ret;
        }
        return 0;
    }
};