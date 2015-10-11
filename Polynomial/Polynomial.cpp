#include <iostream>
#include <algorithm>
#include <cstdio>
#include "polynomial.h"

using namespace std;

typedef struct PolyTerm{
    int coef, exp;
    
    bool operator <(PolyTerm& p){
        return exp < p.exp;
    }
    
    bool operator ==(PolyTerm& p){
        return exp == p.exp;
    }
    
    PolyTerm operator +(PolyTerm& p){
        return PolyTerm{coef + p.coef, exp};
    }
    
}PolyTerm;


void print(PolyTerm *begin, PolyTerm *end){
    while(begin != end){
        printf("%dx^%d ",begin->coef, begin->exp);
        begin++;
    }
}

int main(){
    PolyTerm a[] = {{2,5}, {1,2}, {1,0}};
    PolyTerm b[] = {{3,2}, {2,1}, {1,0}};
    PolyTerm c[6];
    PolyTerm *cend = polynomial_addition<PolyTerm>(c, a, a + 3, b, b + 3);
    print(c, cend);
    return 0;
}