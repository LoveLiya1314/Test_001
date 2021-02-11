#include <iostream>
#include <string>
#include <string>
#include <array>
using namespace std;
int function(int a=1,int b=2){
    printf("a+b==",a+b);
    return a*b;
}
int main()
{

    
    cout << "Hello world"<<<<endl;
    return 0;
}
void quickpass(int r[], int s,int t)
{
	int i=s, j=t, x=r[s];
	while(i<j){	
		while (i<j &&r[j]>x) 
        j=j-1; 
        if (i<j) {
            r[i]=r[j];i=i+1;
            }
		while (i<j && r[i]<x)
         i=i+1;
         if (i<j) {
             r[j]=r[i];j=j-1;
             }
	}
	r[i]=x;
}
//================================================================================================================//
//================================================================================================================//
//================================================================================================================//