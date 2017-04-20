void quickSort(vector<int>& A){
	if(A.size()==0) return;
	quickSortHelp(A, 0, A.size()-1);
}

void quickSortHelp(vector<int>& A, int left, int right){
	if(left>=right) return;
	int j=partition(A, left, right);
	quickSortHelp(A, left, j-1);
	quickSortHelp(A, j+1, right);
}

int partition(vector<int>& A, int left, int right){
	int base = A[left];
	while(left<right){
		while(left<right && A[right)>=base){
			right--;
		}
		A[left]=A[right];
		while(left<right && A[left]<base){
			left++;
		}
		A[right]=A[left];
	}
	A[left]=base;
	return left;
}



void mergeSort(vector<int>& A){
	int low=0,high=A.size()-1;
	mergeSortHelp(A, low, high);
}

void mergeSortHelp(vector<int>& A, int low, int high){
	if(low<high){
		int mid=low+(high-low)/2;
		mergeSortHelp(A, low, mid);
		mergeSortHelp(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

void merge(vector<int>& A, int low, int mid, int high){
	vector<int> B(A.begin(), B.end());
	int i,j,k;
	for(i=low, j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(B[i)<B[j]){
			A[k]=B[i++];
		}else{
			A[k]=B[j++];
		}
	}
	while(i<=mid) A[k++]=B[i++];
	while(j<=mid) A[k++]=B[j++];
}



void heapSort(vector<int>& A){
	int len = A.size();
	for(int i=len/2-1;i>=0;i--){
		adjustHeap(A, i, len);
	}
	for(int i=len-1;i>=0;i--){
		std::swap(A[0],A[i]);
		adjustHeap(A, 0, i);
	}
}

void adjustHeap(vector<int>& A, int start, int len){
	int current=A[start];
	int child=2*start+1;
	while(child<len){
		if(child+1<len && A[child]<A[child+1]){
			child++;
		}
		if(current<A[child]){
			A[start]=A[child];
			start=child;
			child=2*start+1;
		}else{
			break;
		}
	}
	A[start]=current;
}