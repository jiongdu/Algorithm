/**************************************
* @author dujiong
* @date 2016.9.26
* @version V0.1
**************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        int value = 0;
        string ret;
        int index1 = a.size()-1;
        int index2 = b.size()-1;
        int storeValue = 0;
        int carry = 0;
        while(index1 >= 0 || index2 >= 0){
            int temp1 = index1 >= 0 ? a.at(index1) - '0' : 0;
            int temp2 = index2 >= 0 ? b.at(index2) - '0' : 0;
            value = temp1 + temp2 + carry;
            if(value>=2){
                carry = 1;
            }else{
                carry = 0;
            }
            storeValue = value % 2;
            char c = storeValue + '0';
            ret += c;
            index1--;
            index2--;
        }
        if(carry != 0){
            char c = '0' + carry;
            ret += c;
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
	}
};