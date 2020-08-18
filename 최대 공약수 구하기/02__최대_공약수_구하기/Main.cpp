#include <iostream>
using namespace std;


int find_gcd(int, int);

int main() {
	
	int a,b;
	cout <<"a=";
	cin>>a;
	
	cout <<"b=";
	cin>>b;
	
	cout<<"GCD="<<find_gcd(a,b);
	
	return 0;
	
}
int find_gcd(int a, int b){
	while(a!=b){
		if (a>b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}
