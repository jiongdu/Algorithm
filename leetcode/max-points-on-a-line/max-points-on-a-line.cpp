/**************************************
* @author dujiong
* @date 2016.11.22
* @version V0.1
**************************************/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points)
	{
    	int size = points.size();
    	if(size == 0 || size == 1)
        	return size;
 
    	int ret = 0;
    	for(int i = 0; i < size; ++i)
    	{
        	int curmax = 1;
        	map<double,int> mp;
        	int vcnt = 0; 	//垂直点
        	int dup = 0; 	//重复点
        	for(int j = 0; j < size; ++j)
       	 	{
            	if(j != i)
            	{
                	double x1 = points[i].x - points[j].x;
                	double y1 = points[i].y - points[j].y;
                	if(x1 == 0 && y1 == 0)		//和选定的起始点重复的点
                    	dup++;
                	else
                	{
                    	double k = x1 == 0 ? INT_MAX : y1/x1;
                    	if(mp[k] == 0)
                        	mp[k] = 2;
                    	else
                        	++mp[k];
                    	curmax = max(mp[k], curmax);			
                	}                
            	}
        	}
        	ret = max(ret, curmax+dup);      		
    	}
    	return ret;
 	}
};