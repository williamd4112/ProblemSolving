#include <cstdio>

using namespace std;

const int MAX = 102;

long long a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

int main(void){
    
    int nCase;
    scanf("%d",&nCase);
    
    while(nCase--){
        int m, n, p;
        scanf("%d%d%d",&m ,&n ,&p);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%lld",&a[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                scanf("%lld",&b[i][j]);
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < p; j++){
                c[i][j] = 0;
                for(int k = 0; k < n; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < p; j++){
                if(j) putchar(' ');
                printf("%lld",c[i][j]);
            }
            putchar('\n');
        }
        
        if(nCase) putchar('\n');
    }
    
    return 0;
}