/**************************************
* @author dujiong
* @date 2017.2.17
* @version V0.1
**************************************/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int number = 0;
        int length=data.size();
        if(&data[0]!=nullptr && length>0){
            int first = GetFirstK(&data[0], length, k, 0, length-1);
            int last = GetLastK(&data[0], length, k, 0, length-1);
            if(first>-1 && last>-1){
                number=last-first+1;
            }
        }
        return number;
    }
private:
	int GetFirstK(int* data, int length, int k, int start, int end){
        if(start>end){
            return -1;
        }
        int middleIndex = (start+end)/2;
        int middleData = data[middleIndex];
        if(middleData==k){
            if(middleIndex>0 && data[middleIndex-1]!=k || middleIndex==0){
                return middleIndex;
            }else{
                end=middleIndex-1;
            }
        }else if(middleData>k){
        	end = middleIndex-1;        
        }else{
        	start = middleIndex+1;       
        }
        return GetFirstK(data, length, k, start, end);
    }    	
    int GetLastK(int* data, int length, int k, int start, int end){
        if(start>end){
            return -1;
        }
        int middleIndex = (start+end)/2;
        int middleData = data[middleIndex];
        if(middleData==k){
            if(middleIndex<length-1 && data[middleIndex+1]!=k || middleIndex==length-1){
                return middleIndex;
            }else{
                start = middleIndex+1;
            }
        }else if(middleData<k){
            start = middleIndex+1;
        }else{
            end = middleIndex-1;
        }
        return GetLastK(data, length, k, start, end);
    }
    
};