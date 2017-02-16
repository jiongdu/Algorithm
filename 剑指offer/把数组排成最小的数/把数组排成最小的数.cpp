/**************************************
* @author dujiong
* @date 2017.2.16
* @version V0.1
**************************************/

bool strCompare(string a,string b){
    string ab = a+b;
    string ba = b+a;
    return ab.compare(ba) < 0;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        int size = numbers.size();
        if(size==0) return result;
        if(size==1) return result += std::to_string(numbers[0]);
        //转换
        vector<string> strNum;
        strNum.reserve(size);
        for(int num : numbers)
            strNum.push_back(std::to_string(num));
        sort(strNum.begin(),strNum.end(),strCompare);
        for(string str:strNum)
            result += str;
        return result;
    }
};