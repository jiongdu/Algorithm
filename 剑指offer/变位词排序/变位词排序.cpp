/**************************************
* @author dujiong
* @date 2016.10.21
* @version V0.1
**************************************/

class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {

       	vector<string> ret;
        std::sort(str.begin(), str.end());
        set<string> sset;
        for(auto s : str){
            string temp(s);
            std::sort(temp.begin(), temp.end());
            if(sset.count(temp)==0){
                sset.insert(temp);
                ret.push_back(s);
            }
        }
        return ret;
    }

};