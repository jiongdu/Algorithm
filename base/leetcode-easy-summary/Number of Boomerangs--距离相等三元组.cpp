
/*
 * leetcode: 447
 * brust force
 */
 
 int numberOfBoomerangs(vector<pair<int, int>>& points){
	 int res = 0;
	 for(int i=0;i<points.size();i++){
		 unordered_map<double, int> map(points.size());
		 for(int j=0;j<points.size();j++){
			 res += 2 * map[hypot(points[i].first-points[j].first, points[i].second-points[j].second)]++;
		 }
	 }
	 return res;
 }