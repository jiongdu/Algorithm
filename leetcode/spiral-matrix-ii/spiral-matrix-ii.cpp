/**************************************
* @author dujiong
* @date 2016.12.2
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > res(n, vector<int>(n, 0));
        int level=n/2;
        int num=1;
        for(int l=0;l<level;l++){  
        	for(int i=l;i<n-l;i++){  
            	res[l][i]=num++;  
        	}  
        	for(int i=l+1;i<n-l;i++){  
            	res[i][n-1-l]=num++;  
        	}  
        	for(int i=n-2-l;i>=l;i--){  
            	res[n-1-l][i]=num++;  
        	}  
        	for(int i=n-2-l;i>l;i--){  
            	res[i][l]=num++;  
        	}  
    	} 
        if(n%2==1){
            res[level][level]=n*n;
        }
        return res;
    }
};
