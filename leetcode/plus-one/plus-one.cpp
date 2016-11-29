/**************************************
* @author dujiong
* @date 2016.11.29
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		//直接在原digits上操作
        const int num = 1;  
        int carry = num;    
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};