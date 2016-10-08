/**************************************
* @author dujiong
* @date 2016.10.8
* @version V0.1
**************************************/

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {

        stack<int> init;
        stack<int> sorted;
        vector<int> ret;
        for(int i=0;i<numbers.size();++i){
            init.push(numbers[i]);
        }
        while(!init.empty()){
            int temp = init.top();
            init.pop();
            while(!sorted.empty() && temp<sorted.top()){
                init.push(sorted.top());
                sorted.pop();
            }
            sorted.push(temp);
        }
        while(!sorted.empty()){
            ret.push_back(sorted.top());
            sorted.pop();
        }

        return ret;
    }
};