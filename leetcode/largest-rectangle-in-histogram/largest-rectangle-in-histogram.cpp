/**************************************
* @author dujiong
* @date 2016.11.29
* @version V0.1
**************************************/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int sum=0;
        int i=0;
        stack<int> istack;
        while(i<height.size()){
            if(istack.empty() || height[i]>=height[istack.top()]){
                istack.push(i++);
            }else{
                int temp=istack.top();
                istack.pop();
                sum=std::max(sum, height[temp]*(istack.empty()?i:i-istack.top()-1));
                
            }
        }
        return sum;
    }
};