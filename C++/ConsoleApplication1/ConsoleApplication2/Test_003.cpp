#include <iostream>
using namespace std;
int main() {
	int a=10;
	int& i = a;
	cout << a<<endl;
	cout << i << endl;
	cout << &a << endl;
	cout << &i << endl;



	return 0;
}