/**************************************
* @author dujiong
* @date 2016.10.23
* @version V0.1
**************************************/

class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {

        return std::count(article.begin(), article.end(), word);	//O(n)
    }
};