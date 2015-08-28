#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_STR_LEN = 115;
const int MAX_ANS_LEN = 15;

char ans[MAX_ANS_LEN];

void dfs(string &str, int pos, int nc, int np, int c, int p, int si){
	if(nc + np == c + p){
		if(nc == c && np == p){
			for(int i = 0; i < c + p; i++)
				putchar(ans[i]);
			putchar('\n');
		}
	}
	else{
		if(np < p){
			ans[pos] = '_';
			dfs(str, pos + 1, nc, np + 1, c, p, si);
		}

		char lastChar = '\0';
		for(int i = si; i < str.length(); i++){
			if(lastChar == str[i])
				continue;
			ans[pos] = str[i];
			dfs(str, pos + 1, nc + 1, np, c, p, i + 1);
			lastChar = str[i];
		}
	}
}

int main(){

	int nCase;
	cin >> nCase;

	while(nCase--){
		int k, p;
		string str;
		cin >> str >> k >> p;

		sort(str.begin(), str.end());
		dfs(str, 0, 0, 0, k, p, 0);
		putchar('\n');
	}

	return 0;
}