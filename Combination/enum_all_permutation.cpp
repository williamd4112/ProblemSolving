#include <iostream>

using namespace std;

const int MAX_LEN = 10;

char ans[MAX_LEN + 1]; 
bool used[MAX_LEN + 1];

void backtrack(string& str, int n){
	if(n == str.length()){
		ans[n] = '\0';
		cout << ans << endl;
	}
	else{
		for(int i = 0; i < str.length(); i++){
			if(!used[i]){
				used[i] = true;
				ans[n] = str[i];
				backtrack(str, n + 1);
				used[i] = false;
			}
		}
	}
}

int main(){

	string s = "abc";
	backtrack(s, 0);

	return 0;
}