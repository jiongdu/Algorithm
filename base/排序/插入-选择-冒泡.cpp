void insertSort(vector<int>& A){
	int len = A.size();
	if(len==0) return;
	for(int i=1;i<len;++i){
		int temp = A[i];
		int j;
		for(j=i-1;j>=0$$temp<A[j];j--){
			A[j+1]=A[j];
		}
		A[j+1]=temp;
	}
}

void selectionSort(){
	if(A.size()==0||A.size()==1) return;
    int len=A.size();
    int min;
    for(int i=0;i<len;i++){
        min=i;
        for(int j=i;j<len;j++){
        if(A[j]<A[min]){
            min=j;
        }
		std::swap(A[min],A[i]);
    }
}

void bubbleSort(vector<int>& A){
	if(A.size()==0||A.size()==1) return;
    int len=A.size();
    for(int i=0;i<len;i++){
        bool flag=false;
        for(int j=0;j<len-1-i;j++){
			if(A[j]>A[j+1]){
                std::swap(A[j],A[j+1]);
                flag=true;
            }
        }
        if(flag==false) return;
    }
}
