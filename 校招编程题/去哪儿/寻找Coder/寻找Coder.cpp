/**************************************
* @author dujiong
* @date 2016.7.22
* @version V0.1
**************************************/

class Coder {
public:
    vector<string> findCoder(vector<string> A, int n){
        multimap<int,string,greater<int>> mapCoder;
        vector<string> vec;
        for(int i=0;i<n;i++){
            string s;
            bool flag=true;
            for(string::iterator it=A[i].begin();it!=A[i].end();++it){
                char c=toupper(*it);
                s.push_back(c);
            }
            int count;
            count=findString(s);
            if(count==0) break;
            else{
                mapCoder.insert(make_pair(count,A[i]));
            }
        }
        for(multimap<int,string,greater<int>>::iterator it=mapCoder.begin();
           it!=mapCoder.end();++it){
            vec.push_back(it->second);
        }
        return vec;
    }
private:
    int findString(string s){
            int count=0;
            auto start=0;
            while(1){
                auto temp=s.find("CODER",start);
                if(temp==string::npos){
                    break;
                }
                start=temp+5;
                count++;
            }
        return count;
    }
};
