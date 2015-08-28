#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char ans[10 + 2];
bool used[10 + 2];

void backtrack(string &str, int startIndex, int endIndex){
	if(startIndex > endIndex){
		for(int i = 0; i <= endIndex; i++){
			cout << ans[i];
		}
		cout << endl;
	}
	else{
		char lastChar = '\0';
		for(int i = 0; i <= endIndex; i++){
			// Avoid repeated character
			if(used[i] == false && used[i + 1] == true && str[i] == str[i + 1])
				continue;
			if(!used[i]){
				used[i] = true;
				ans[startIndex] = str[i];
				backtrack(str, startIndex + 1, endIndex);
				used[i] = false;
			}
		}
	}
}

int main(){

	int nCase;
	cin >> nCase;

	while(nCase--){
		memset(ans, '\0', sizeof(ans));
		memset(used, false, sizeof(used));
		
		string str;
		cin >> str;

		sort(str.begin(), str.end());
		backtrack(str, 0, str.length() - 1);
		cout << endl;
	}

	return 0;
}