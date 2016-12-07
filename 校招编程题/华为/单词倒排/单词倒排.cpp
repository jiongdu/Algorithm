/**************************************
* @author dujiong
* @date 2016.12.7
* @version V0.1
**************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		vector<string> array;
		string temp;
		for(int i=0;i<str.length();i++){
			if(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
				while(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
					temp += str[i];
					i++;
				}
				array.push_back(temp);
				temp.clear();
			}
		}
		for(int i=array.size()-1;i>0;i--){
			cout << array[i] << ' ';
		}
		cout << array[i] << endl;
	}
	return 0;
}
