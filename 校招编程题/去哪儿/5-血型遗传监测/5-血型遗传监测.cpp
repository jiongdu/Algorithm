/**************************************
* @author dujiong
* @date 2016.8.24
* @version V0.1
**************************************/

class ChkBloodType {
public:
    vector<string> chkBlood(string father, string mother) {
    	string s = father + mother;
		vector<string> vs;
		if(s=="OO")
			vs.push_back("O");
		else if(s=="AO"||s=="OA")
        {
            vs.push_back("A");
            vs.push_back("O");
        }
        else if(s=="AA")
        {
            vs.push_back("A");
            vs.push_back("O");
        }
        else if(s=="AB"||s=="BA")
        {
            vs.push_back("A");
            vs.push_back("AB");
            vs.push_back("B");
            vs.push_back("O");
        }
        else if(s=="AAB"||s=="ABA")
        {
            vs.push_back("A");
            vs.push_back("AB");
            vs.push_back("B");
        }
        else if(s=="BO"||s=="OB")
        {
            vs.push_back("B");
            vs.push_back("O");
        }
        else if(s=="BB")
        {
            vs.push_back("B");
            vs.push_back("O");
        }
        else if(s=="BAB"||s=="ABB")
        {
            vs.push_back("A");
            vs.push_back("AB");
            vs.push_back("B");
        }
        else if(s=="ABO"||s=="OAB")
        {
            vs.push_back("A");
            vs.push_back("B");
        }
        else if(s=="ABAB")
        {
            vs.push_back("A");
            vs.push_back("AB");
            vs.push_back("B");
        }
        return vs;
    }
};
