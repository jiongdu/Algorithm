/**************************************
* @author dujiong
* @date 2016.11.28
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > ret;
        if(num.size()<3){
            return ret;
        }
        vector<int> temp(3,0);
        std::sort(num.begin(), num.end());
        int last=num[0];
        for(int i=0;i<num.size()-1 && num[i]<=0;i++){
			if(i && num[i]==last)
                continue;
            int left=i+1;
            int right = num.size()-1;
            while(left < right){
                int sum = num[left]+num[right];
                if(sum+num[i]==0){
                    temp[0]=num[i];
                    temp[1]=num[left];
                    temp[2]=num[right];
                    ret.push_back(temp);
                    left++;
                    right--;
                }else if(sum+num[i]<0){
                    left++;
                }else{
                    right--;
                }
            }
            last = num[i];
        }
        ret.erase(unique(ret.begin(),ret.end()), ret.end());
        return ret;
    }
};