/**************************************
* @author dujiong
* @date 2017.2.13
* @version V0.1
**************************************/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0){
            return 0;
        }
        int index1=0;
        int index2=rotateArray.size()-1;
        int mid;
        while(rotateArray[index1]>=rotateArray[index2]){
            if(index2-index1==1){
                mid=index2;
                break;
            }
            mid=index1+(index2-index1)/2;
            if(rotateArray[mid]==rotateArray[index1] &&
              rotateArray[index1]==rotateArray[index2])
                	return MinInOrder(rotateArray, index1, index2);
            if(rotateArray[mid]>=rotateArray[index1]){
                index1=mid;
            }else if(rotateArray[mid]<=rotateArray[index2]){
                index2=mid;
            }
        }
        return rotateArray[mid];
    }
    int MinInOrder(vector<int> rotateArray, int index1, int index2){
        
        int result=rotateArray[index1];
        for(int i=index1+1;i<=index2;i++){
            if(rotateArray[i]<result){
                result=rotateArray[i];
            }
        }
        return result;
    }
};