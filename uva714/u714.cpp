#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_NUM_BOOKS = 502;

typedef struct Bound {
    long long lowerBound;
    long long upperBound;
}Bound;

long long books[MAX_NUM_BOOKS];

Bound load(int nBook){
    Bound bound{0, 0};
    
    for(int i = 0; i < nBook; i++){
        cin >> books[i];
        bound.upperBound += books[i];
        bound.lowerBound = max(bound.lowerBound, books[i]);
    }
    
    return bound; 
}

long long divide(int nBook, long long max){
    long long partialSum = 0;
    long long cPart = 1;
    
    for(int i = 0; i < nBook; i++){
        if(partialSum + books[i] > max){
            cPart++;
            partialSum = 0;
        }    
        partialSum += books[i];
    }
    
    return cPart;
}

long long findMinMax(int nBook, int nPart, Bound bound){
    while(bound.lowerBound < bound.upperBound){
        long long mid = bound.lowerBound + (bound.upperBound - bound.lowerBound) / 2;
        
        long long result = divide(nBook, mid);
        if(result > nPart){ // lower bound too small
            bound.lowerBound = mid + 1;
        }
        else { // upper bound too large
            bound.upperBound = mid;
        }
    }
    
    return bound.upperBound;
}

void solve(int minmax, int nBook, int nPart){
    bool outputMark[MAX_NUM_BOOKS];
    memset(outputMark, false, sizeof(outputMark));
    
    long long sum = 0;
    long long cPart = nPart - 1;
    for(int i = nBook - 1; i >= 0; i--){
        if(sum + books[i] > minmax || cPart > i){ // cPart > i: everyone must own a part
            sum = 0;
            cPart--;
            
            // Mark a slash position
            outputMark[i] = true;   
        }
        sum += books[i];
    }
    
    int endIndex = nBook - 1;
    for(int i = 0; i < nBook; i++){
        cout << books[i];
        if(i != endIndex) {
            cout << ((outputMark[i]) ? " / " : " ");
        }
    }
    cout << endl;
}

int main(){
    
    int nCase;
    int nBook, nPart;
    
    cin >> nCase;
    
    while(nCase--){
        cin >> nBook >> nPart;
        memset(books, 0, sizeof(books));
        
        Bound bound = load(nBook);
        
        long long minmax = findMinMax(nBook, nPart, bound);
        solve(minmax, nBook, nPart);
    }
    
    return 0;
}