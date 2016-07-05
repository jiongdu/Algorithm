class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ret;
      std::sort(strs.begin(), strs.begin());

      map<string, vector<string>> strMap;
      for(int i=0;i<strs.size();++i)
      {
          strMap[getString(strs[i])].push_back(strs[i]);
      }
      for(map<string, vector<string>>::iterator it = strMap.begin();it!=strMap.end();++it)
      {
          ret.push_back(it->second);
      }
      return ret;

    }
private:
    string getString(string s)
    {
        std::sort(s.begin(), s.end());
        return s;
    }
};
