/**************************************
* @author dujiong
* @date 2016.10.20
* @version V0.1
**************************************/

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {

        stack<char> cStack;
        for(int i=0;i<n;i++){
            if(A[i]!='(' && A[i]!=')'){
                return false;
            }else if(A[i]=='('){
                cStack.push(A[i]);
            }else if(A[i]==')'){
                if(cStack.empty()){
                    return false;
                }
                cStack.pop();
            }
        }
        return cStack.empty() ? true : false;

    }
};