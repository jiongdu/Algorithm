/**************************************
* @author dujiong
* @date 2017.2.13
* @version V0.1
**************************************/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		bool ret = VerifyBST(&sequence[0], sequence.size());
        return ret;
    }
    bool VerifyBST(int* sequence, int length){
        if(sequence==nullptr || length<=0){
            return false;
        }
        int root = sequence[length-1];
        int i=0;
        for(;i<length-1;i++){
            if(sequence[i]>root){
                break;
            }
        }
        int j=i;
        for(;j<length-1;j++){
            if(sequence[j]<root){
                return false;
            }
        }
        bool left = true;
        if(i>0){
            left = VerifyBST(sequence, i);
        }
        bool right=true;
        if(i<length-1){
            right = VerifyBST(sequence+i,length-1-i);
        }
        return (left&&right);
    }
};