/**************************************
* @author dujiong
* @date 2016.8.19
* @version V0.1
**************************************/

class Balls {
public:
    int calcDistance(int A, int B, int C, int D) {
    	return A+B+C+D+2*(A+B+C+D);
    }
};
