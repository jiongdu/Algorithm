/**************************************
* @author dujiong
* @date 2016.11.29
* @version V0.1
**************************************/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int closet=65535;			
        int sum;
        int last = num[0];
        for(int i=0;i<num.size()-2;i++){
            if(i!=0 && num[i]==last) continue;
            int left=i+1;
            int right=num.size()-1;
            int ret;
            while(left<right){
                ret = num[i]+num[left]+num[right];
     			if(abs(ret-target)<closet){
                    closet = abs(ret-target);
                    sum = ret;
                }
                if(ret==target){
                    return sum;
                }else if(ret<target){
                    left++;
                }else{
                    right--;
                }
            }
            last = num[i];
        }
        return sum;
    }
};