
/* leetcode: 455
 * two pointer
 */
 
int findContentChildren(vector<int>& g, vector<int>& s){
	std::sort(g.begin(), g.end());
	std::sort(s.begin(), s.end());
	int len1 = g.size();
	int len2 = s.size();
	if(len1==0 || len2==0) return 0;
	int i=0;
	for(int j=0;i<len1&&j<len2;j++){
		if(g[i]<=s[j]){
			i++;
		}
	}
	return i;
}