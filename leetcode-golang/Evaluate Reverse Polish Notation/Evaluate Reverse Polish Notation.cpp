class Solution {
	public:
		int evalRPN(vector<string>& tokens) {
            stack<int> s;
            for (int i = 0; i < tokens.size(); i++ ) {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){   //操作符
                    if (s.size() < 2) {     //stack中的操作数不可能小于2
                        return 0;
                    }
                    int nums2 = s.top();
                    s.pop();
                    int nums1 = s.top();
                    s.pop();
                    if (tokens[i] == "+") {
                        s.push(nums1+nums2);
                    } else if (tokens[i] == "-") {
                        s.push(nums1-nums2);
                    } else if (tokens[i] == "/") {
                        s.push(nums1/nums2);
                    } else if (tokens[i] == "*") {
                        s.push(nums1*nums2);
                    }
                } else {        //数字
                    s.push(std::stoi(tokens[i]));
                }
            }
            if(s.size() != 1) {
                return 0;
            }
            return s.top();
 		}   
};
