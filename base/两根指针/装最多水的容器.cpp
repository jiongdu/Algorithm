int maxArea(vector<int>& heights){
	int res=0,i=0,j=heights.size()-1;
	while(i<j){
		res = max(res, min(heights[i], heights[j])*(j-i));
		heights[i]<heights[j] ? ++i:--j;
	}
	return res;
}