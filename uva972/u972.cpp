#include <iostream>
#include <algorithm>
#include <vector>
#include <cfloat>
#include <cstdio>

using namespace std;

typedef struct Line {
    double x1, x2, value;
}Line;

void readData(vector<Line>& v, int num){
    double x = 0;
    for(int i = 0; i < num; i++){
        double value, length;
        cin >> value >> length;
        
        double x1 = x, x2 = x + length;
        v.push_back(Line{x1, x2, value});
        
        x = x2;
    }
}

double solve(vector<Line>& fv, vector<Line>& gv){
    double ans = DBL_MAX;
    
    vector<Line>::iterator fit = fv.begin(), git = gv.begin();
    while(fit != fv.end() & git != gv.end()){
        ans = min(ans, max(fit->value, git->value));
        if(fit->x2 < git->x2)
            fit++;
        else if(fit->x2 > git->x2)
            git++;
        else
            fit++, git++;
    }
    
    while(fit != fv.end())
        ans = min(ans, max(fit++->value, (git - 1)->value));
    while(git != gv.end())
        ans = min(ans, max((fit - 1)->value, git++->value));
    
    return ans;
}

int main(){
        
    int nf, ng;
    while(cin >> nf){
        vector<Line> fv, gv;
        
        readData(fv, nf);
        
        cin >> ng;
        
        readData(gv, ng);
        
        double ans = solve(fv, gv);
        printf("%.3lf\n",ans);
    }
    
    return 0;
}