/**************************************
* @author dujiong
* @date 2016.10.21
* @version V0.1
**************************************/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        //vector<string> res;
       	vector<string> ret(strs.begin(),strs.end());
    	for(int i=0;i<ret.size();i++){
        	std:sort(ret[i].begin(), ret[i].end());
    	}
   
    	map<string, int> m;
    	for(int i=0;i<ret.size();i++){
        	if(m.find(ret[i])==m.end()){
            	m[ret[i]]=1;
        	}else{
            	m[ret[i]]++;
        	}
    	}
        /*
        for(int i=0;i<ret.size();i++){
			if(m[ret[i]]>=2){
                res.push_back(strs[i]);
            }
        }
        return res;
        */
        int j=0;
        for(int i=0;i<ret.size();i++){
			if(m[ret[i]]>=2){
				ret[j++]=strs[i];
            }
        }
        ret.erase(ret.begin()+j,ret.end());
        return ret;
    }
};