#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 49;
const int LIMIT = 6;

int data[MAX];
int ans[LIMIT];

void backtrack(int pos, int startIndex, int endIndex, int size, int limit){
	if(size == limit){
		for(int i = 0; i < LIMIT; i++){
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	else{
		for(int i = startIndex; i <= endIndex; i++){
			ans[pos] = data[i];
			backtrack(pos + 1, i + 1, endIndex, size + 1, limit);
		}
	}
}

int main(){

	int n, cCase = 0;
	while(cin >> n, n){
		for(int i = 0; i < n; i++){
			cin >> data[i];
		}
		if(cCase++) cout << endl;
		backtrack(0, 0, n - 1, 0, LIMIT);
	}

	return 0;
}