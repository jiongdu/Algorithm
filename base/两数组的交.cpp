vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	vector<int> result;
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_insert(result));
	result.erase(std::unique(result.begin(), result.end()), result.end());
	return result;
}