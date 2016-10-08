/**************************************
* @author dujiong
* @date 2016.10.8
* @version V0.1
**************************************/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ret;
        if(stack2.size()==0){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
        }
        ret = stack2.top();
        stack2.pop();
   
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};