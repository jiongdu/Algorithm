/**************************************
* @author dujiong
* @date 2016.10.23
* @version V0.1
**************************************/

class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        // write code here
        //std::reverse(AB.begin(), AB.end());
        //return AB;
        AB[0]=AB[0]^AB[1];
        AB[1]=AB[1]^AB[0];
       	AB[0]=AB[0]^AB[1];
        return AB;
    }
};