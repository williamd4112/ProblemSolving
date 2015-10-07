#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	float x, p;
	cin >> x >> p;
	
	float a = x;
	float b = a + 0.5f * 0.25f;
	float c = (b * 128);
	printf("%f\n%f\n%f\n",a,b,c);
	cout << a << endl
	     << b << endl
	     << c << endl;
	return 0;
}
