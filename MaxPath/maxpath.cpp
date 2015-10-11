#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

int solve(vector<int>& tree){
	int maxw = 0;
	for(int i = tree.size() - 1; i > 0; i--){
		int ni = i;
		while((ni /= 2) > 0)
			tree[i] += tree[ni];
		maxw = max(tree[i], maxw);
	}
	
	return maxw;
}

int main() {
	// freopen("in.txt","r",stdin);
	string line;
	while(getline(cin, line) != NULL){
		stringstream ss(line);
		
		vector<int> tree;
		tree.push_back(0); // Fake
		
		int num;
		while(ss >> num)
			tree.push_back(num);
		cout << solve(tree) << endl;
	}
	
	return 0;
}