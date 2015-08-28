#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_STR_LEN = 115;
const int MAX_ANS_LEN = 15;

char ans[MAX_ANS_LEN];

void dfs(string &str, int nc, int c, int si){
	if(nc == c){
		for(int i = 0; i < c; i++)
			putchar(ans[i]);
		putchar('\n');
	}
	else{
		char lastChar = '\0';
		for(int i = si; i < str.length(); i++){
			if(lastChar == str[i])
				continue;
			ans[nc] = str[i];
			dfs(str, nc + 1, c, i + 1);
			lastChar = str[i];
		}
	}
}

int main(){

	int nCase;
	cin >> nCase;

	while(nCase--){
		int k;
		string str;
		cin >> str >> k;

		sort(str.begin(), str.end());
		dfs(str, 0, k, 0);
		putchar('\n');
	}

	return 0;
}