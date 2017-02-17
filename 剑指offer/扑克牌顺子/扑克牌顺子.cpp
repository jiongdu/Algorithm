/**************************************
* @author dujiong
* @date 2017.2.17
* @version V0.1
**************************************/

class Solution {
public:
    bool IsContinuous(vector<int> numbers ) {
        if(numbers.size()==0){
            return false;
        }
        std::sort(numbers.begin(), numbers.end());
        int numberOfGap=0;
        int numberOfZero = std::count(numbers.begin(), numbers.end(), 0);
        
        int small = numberOfZero;
        int big = small+1;
        while(big<numbers.size()){
            if(numbers[small]==numbers[big]){
                return false;
            }
            numberOfGap += numbers[big]-numbers[small]-1;
            small=big;
            ++big;
        }
        return numberOfZero>=numberOfGap;
        
    }
};