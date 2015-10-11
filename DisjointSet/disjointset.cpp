#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 10000

using namespace std;

int parent[MAX]; 

void simpleUnion(int i, int j){
    parent[j] = i;
}

void weightedUnion(int i, int j){
    int tmp = parent[i] + parent[j];
    if(-parent[i] >= -parent[j]){
        parent[i] = tmp;
        parent[j] = i;
    }
    else{
        parent[i] = j;
        parent[j] = tmp;
    }
}

int find(int i){
    return (parent[i] < 0) ? i : (parent[i] = find(parent[i]));
}

int main(){
    freopen("in.txt", "r", stdin);
    fill(parent, parent + MAX, -1);
    
    int n;
    cin >> n;
    
    int ne, root, e;
    for(int i = 0; i < n; i++){
        cin >> ne;
        cin >> root;
        parent[root] = -ne;
        for(int j = 1; j < ne; j++){
            cin >> e;
            parent[e] = root;
        }
    }
    
    int nu;
    cin >> nu;
    int node_i, node_j;
    for(int i = 0; i < nu; i++){
        cin >> node_i >> node_j;
        //simpleUnion(node_i, node_j);
        weightedUnion(node_i, node_j);
    }
    
    int find_i;
    while(cin >> find_i){
        find(find_i);
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ",parent[i]);
    cout << endl;

    
    return 0;
}