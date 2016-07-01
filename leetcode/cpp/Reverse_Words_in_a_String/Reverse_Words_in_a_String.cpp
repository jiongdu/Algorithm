class Solution {
public:
    void reverseWords(string &s) {
        std::reverse(s.begin(),s.end());
        stringstream ss(s);
        s.clear();
        string tmp;
        while(ss >> tmp)
        {
            std::reverse(tmp.begin(),tmp.end());
            s += tmp + " ";
        }
        if(!s.empty()) s.erase(s.size()-1);
    }
};
