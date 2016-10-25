/**************************************
* @author dujiong
* @date 2016.10.25
* @version V0.1
**************************************/

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {

        vector<int> ret;
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
			int top = s.top();
            while(top!=-1 && A[i]>=top){
                s.pop();
                top = s.top();
            }
            s.push(A[i]);
            ret.push_back(top);
            
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};