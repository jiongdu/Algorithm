/**************************************
* @author dujiong
* @date 2016.9.20
* @version V0.1
**************************************/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> istack;
        int temp1,temp2;
        for(int i=0;i<tokens.size();i++){
            if (tokens[i] == "+" || tokens[i] == "-" ||
                	tokens[i] == "*" || tokens[i] == "/"){
                temp1=istack.top();
            	istack.pop();
            	temp2=istack.top();
            	istack.pop();
                switch(*(tokens[i].c_str())){
                    case '+':
                		temp2+=temp1;
                		break;
                	case '-':
                		temp2-=temp1;
                		break;
                	case '*':
                		temp2*=temp1;
                		break;
                	case '/':
                        temp2/=temp1;
                		break;
               }
               istack.push(temp2);
            }else{
               istack.push(atoi(tokens[i].c_str()));
            }
    	}
        return istack.top();
    }
};
