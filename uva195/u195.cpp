#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp(char a, char b){
 	char lower_a = tolower(a), lower_b = tolower(b);
 	return (lower_a == lower_b) ? a < b : lower_a < lower_b;
}

int main(){

	int nCase;
	cin >> nCase;

	while(nCase--){
		string str;
		cin >> str;

		sort(str.begin(), str.end(), cmp);

		do{
			cout << str << endl;
		}while(next_permutation(str.begin(), str.end(), cmp));
	}
}