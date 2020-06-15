#include <iostream>
using namespace std;


int find_gcd(int, int);

int main() {
	
	int a,b;
	cout <<"a="; 
	cin>>a; //1.a입력받기
	
	cout <<"b=";
	cin>>b; //2.b입력받기
	
	cout<<"GCD="<<find_gcd(a,b); //3.최대공약수 함수 호출
	
	return 0;
	
}
//최대공약수 함수 정의
int find_gcd(int a, int b){
	while(a!=b){ //두 수가 같아질 때까지 계속 빼다가 a 리턴하기
		if (a>b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}
