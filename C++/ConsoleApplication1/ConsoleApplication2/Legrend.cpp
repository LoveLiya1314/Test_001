#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>
#include <typeindex>

using namespace std;
int Legrend(long int a,long int b)

{
	if (a == 1)
		return 1;
	if (b % a == 0)
		return 0;
	if (a % 2 == 0)
		return Legrend(a / 2, b) * pow(-1, (pow(b, 2) - 1) / 8);
	return Legrend(b%a, a)*pow(-1, (a - 1)*(b - 1) / 4);
}



int main_Legrend() {
	long int a, b; 
	
	while (1)
	{
	cin>> a;
	if (a==0) {
		break;
	}
	cin >> b;
	int c = Legrend(a, b);
	cout << c << endl;
	}
	
	system("pause");
	return 0;
}