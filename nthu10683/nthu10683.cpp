#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

typedef long long ll;

const int S = 1002;
const int K = 12;

string solve(string str, int k){
    stringstream ss;
    for(string::iterator it = str.begin(); it != str.end();){
        int count = 0;
        char ch = *it;
        for(;*it == ch; it++, count++);
        ss << count << ch;
    }
    
    if(k > 1){
        return solve(ss.str(), --k);
    }else{
        return ss.str();
    }
}

int main(){
    
    int nCase;
    cin >> nCase;
    
    while(nCase--){
        string s;
        cin.ignore();
        getline(cin ,s);
        //cout << s << endl;
        
        int k;
        cin >> k;
        //cout << k << endl;
        
        cout << solve(s, k) << endl;
    }
    
    return 0;
}