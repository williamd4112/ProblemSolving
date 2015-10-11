#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// -1: not exist
// 0: correct
// 1: wait for guessing
int counter[26] = {0};

int main(){
    
    int t;
    while(cin >> t){
        memset(counter, 0, sizeof(counter));
        char c;
        
        cin.ignore();
        while(cin >> c, c != '\n'){
            counter[c - 'a'] = 1;
        }
        
        cin.ignore();
        int nGuess = 0;
        int nError = 0;
        while(cin >> c, c != '\n'){
            int index = c - 'a';
            nGuess++;
            if(counter[index] < 0){
               nError++; 
            }
            else if(counter[index] > 0){
                counter[index] = 0;
            }
        }
        
        if(nGuess < 7){
            cout << "You chickened out." << endl;
        }
        else if(){
            
        }
    }
    
    return 0;
}