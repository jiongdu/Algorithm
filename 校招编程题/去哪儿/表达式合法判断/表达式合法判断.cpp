/**************************************
* @author dujiong
* @date 2016.8.18
* @version V0.1
**************************************/

class ChkExpression {
public:
    bool chkLegal(string A) {
        // write code here
        vector<char> stack;
        for(int i=0;i<A.size();++i){
            if((A[i]=='{') || (A[i]=='[') || (A[i]=='('))
                stack.push_back(A[i]);
            else if((A[i]=='}') || (A[i]==')') || (A[i]==']')){
                if(stack.size()<1) return false;
                stack.pop_back();
            }
        }
        if(stack.size()>0) return false;
        return true;
    }
};
