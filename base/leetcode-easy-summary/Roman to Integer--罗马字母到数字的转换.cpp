
/*
 * leetcode: 13
 */
 
 int romanToInt(string s){
	unordered_map<char, int> T={{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000} };
	int length = s.length();
	int sum = T[s[length-1]];
	for(int i=length-2;i>=0;i--){
		if(T[s[i]]<T[s[i+1]]){
			sum -= T[s[i]];
		}else{
			sum += T[s[i]];
		}
	}
	return sum;
 }