#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

const int MAXF = 100002;

int id;
map<string, int> name_hash;
int getID(string name){
    if(!name_hash.count(name))
        name_hash[name] = id++;
    return name_hash[name];
}

int parent[MAXF << 1];
void init(){
    for(int i = 0; i < (MAXF << 1); i++)
        parent[i] = -1;
    id = 0;
}

void unions(int i, int j){
    int tmp = parent[i] + parent[j];
    if(-parent[i] >= -parent[j]){
        parent[i] = tmp;
        parent[j] = i;
    }
    else{
        parent[i] = j;
        parent[j] = tmp;
    }
    cout << -tmp << endl;
}

int find(int i){
    return (parent[i] < 0) ? i : (parent[i] = find(parent[i]));
}

void load(int nF){
    string src, dst;
    for(int i = 0; i < nF; i++){
        cin >> src >> dst;
        unions(find(getID(src)), find(getID(dst)));
    }
}

int main(){
    
    int nCase;
    cin >> nCase;
    
    while(nCase--){
        int nF;
        cin >> nF;
        init();
        load(nF);
    }
    
    return 0;
}