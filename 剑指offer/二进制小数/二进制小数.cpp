/**************************************
* @author dujiong
* @date 2016.10.9
* @version V0.1
**************************************/

class BinDecimal {
public:
    string printBin(double num) {
        string str("0.");
        double base = 0.5;
        while(num>0){
            if(num>=base){
				num-=base;
                str+='1';
            }else{
                str+='0';
            }
            base/=2;
            if(str.size()>32){
                str = "Error";
                break;
            }
        }
        return str;
    }
};