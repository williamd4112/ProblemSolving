#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
    
    float x, p;
    scanf("%f%f",&x ,&p);
    
    float ans = round(x * (1.0f / p)) * p;
    printf("%.4f\n",ans);
    
    
    return 0;
}