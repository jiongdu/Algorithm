class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() == 0 && t.length()==0)
            return true;
        if(s.length()!=t.length())
            return false;

        map<char,int> c;
        for(int i=0;i<s.length();++i)
        {
            if(c.count(s[i]))
            {
                c[s[i]]++;
            }
            else
            {
                c[s[i]]=1;
            }
        }
        for(int i=0;i<t.length();++i)
        {
            if(c.count(t[i]))
            {
                c[t[i]]--;
            }
            else
            {
                c[t[i]]=1;
            }
        }
        for(auto p = c.begin();p!=c.end();++p)
        {
            if(p->second!=0)
                return false;
        }
        return true;
    }
};
