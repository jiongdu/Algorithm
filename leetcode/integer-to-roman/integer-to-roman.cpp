/**************************************
* @author dujiong
* @date 2016.11.25
* @version V0.1
**************************************/

class Solution {
public:
    string intToRoman(int num) {
        vector<string> one={"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> ten={"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hun={"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tho={"M", "MM", "MMM"};
        
        string ret;
        
        if(num>=1000){
        	ret+=tho[num/1000-1];
            num=num%1000;
        }
        if(num>=100){
            ret+=hun[num/100-1];
            num=num%100;
        }
        if(num>=10){
            ret+=ten[num/10-1];
            num=num%10;
        }
        if(num>=1){
            ret+=one[num%10-1];
   			return ret;
        }
        return ret;
        
    }
};