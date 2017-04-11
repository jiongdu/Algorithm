int lengthOfLongestSubstring(string s){
	map<char, int> imap;
	int ans=0,temp=0;
	for(int i=0;i<s.length();++i){
		if(imap.find(s[i])==imap.end()){
			++temp;
		}else{
			int start=i-temp;			//  example: "an+-na"
			if(imap[s[i]]>=start){		//
				temp=i-imap[s[i]];		//
			}else{						//
				++temp;					//
			}
		}
		imap[s[i]]=i;
		if(ans<temp) ans=temp;
	}
	return ans;
}