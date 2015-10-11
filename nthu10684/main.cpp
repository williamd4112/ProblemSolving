#include <iostream>
#include <list>
#include <cstdio>

#define TABLE_SIZE 7

using namespace std;

int h(int val){
    return (2 * val - 1) % TABLE_SIZE;
}

list<int> hash_table[TABLE_SIZE];

int main(){
    
    int nCase;
    cin >> nCase;
    
    string op;
    int val;
    
    while(nCase--){
        cin >> op >> val;
        
        if(op == "Insert") {
            hash_table[h(val)].push_back(val);    
        }
        else if(op == "Delete"){
            hash_table[h(val)].remove(val);
        }
    }
    
    for(int i = 0; i < 7; i++){
        printf("[%d]",i);
        list<int>& node = hash_table[i];
        for(list<int>::iterator it = node.begin(); it != node.end(); it++){
            if(it == node.begin())
                printf("%d",*it);
            else
                printf("->%d",*it);
        }
        
        if(i != 6)
            putchar('\n');
    }
    
    return 0;
}