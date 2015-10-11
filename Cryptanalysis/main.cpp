#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct CharCt{
    char c;
    int num;
    
    friend bool operator <(const CharCt a, const CharCt b){
        return (a.num == b.num) ? a.c < b.c : a.num > b.num;
    }
    
}CharCt;

int toIndex(char c){
    return c - 'A';
}

CharCt cts[26];
char maxc = 'A';

int main(){
    for(int i = 0; i < 26; i++)
        cts[i] = CharCt{('A' + i), 0};
        
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string line;
        getline(cin, line);
        
        for(string::iterator it = line.begin(); it != line.end(); it++){
            char c = *it;
            if(isalpha(c)){
                if(islower(c))
                    c = toupper(c);
                cts[toIndex(c)].num++;
                maxc = max(maxc, c);
            }
        }
    }
    
    stable_sort(cts, cts + 26);
    for(int i = 0; i < 26; i++){
        if(cts[i].num > 0){
            printf("%c %d\n",cts[i].c, cts[i].num);
        }
    }
    
    return 0;
}