/**************************************
* @author dujiong
* @date 2016.10.9
* @version V0.1
**************************************/

/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/
class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {

        double x1=(A[0].x+A[2].x)/2;   //第一个中心点横坐标
        double x2=(B[0].x+B[2].x)/2;
        double y1=(A[0].y+A[2].y)/2;   //第一个中心点纵坐标	
        double y2=(B[0].y+B[2].y)/2;
        
        double s=(y1-y2)/(x1-x2);
        double y=y1-s*x1;
        
        vector<double> ret;
        ret.push_back(s);
        ret.push_back(y);
        return ret;
    }
};