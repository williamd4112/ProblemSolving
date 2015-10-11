#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1000005;

int vn[MAX] ,vm[MAX], result[MAX];

int main(void){
    
    int n, m;
    while(scanf("%d",&n) == 1, n){
        for(int i = 0; i < n; i++)
            scanf("%d",&vn[i]);
            
        scanf("%d",&m);
        for(int i = 0; i < m; i++)
            scanf("%d",&vm[i]);
        
        sort(vn, vn + n);
        sort(vm, vm + m);

        int *end = set_intersection(vn, vn + n, vm, vm + m, result);
        if(end == result) {
            printf("empty");
        }
        else {
            for(int *it = result; it != end; it++){
                if(it != result) putchar(' ');
                printf("%d",*it);
            }
        }
        putchar('\n');
    }
    
    return 0;
}