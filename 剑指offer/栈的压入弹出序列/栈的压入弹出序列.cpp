/**************************************
* @author dujiong
* @date 2017.2.15
* @version V0.1
**************************************/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()){
            return false;
        }
        if(pushV.size()==0 && popV.size()==0){
            return true;
        }
        stack<int> istack;
        int i=0;	//遍历popV
        int temp=0;	//pushV开始找的地方
        while(i<popV.size()){
            int j;
            if(!istack.empty() && istack.top()==popV[i]){
                istack.pop();
                i++;
                continue;
            }
            if(temp>=popV.size()){
                return false;
            }
            for(j=temp;j<pushV.size();j++){			//直到相等，不然就一直入栈
                if(pushV[j]==popV[i]){
                    break;
                }else{
                    istack.push(pushV[j]);
                }
            }
            if(j>=pushV.size()){
                return false;
            }
            temp=j+1;
            i++;
        }
        return true;
    }
};