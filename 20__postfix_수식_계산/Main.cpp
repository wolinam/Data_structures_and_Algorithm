//postfix 표기법 계산하기
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define MAX_STACK_SIZE 100

inline void error(char* str){//에러발생시 문장 출력
	fprintf(stderr,"%s\n",str);
	exit(1);
};

class OperandStack{ //stack 구현하는 객체
	double data[MAX_STACK_SIZE]; //stack 담는 배열 생성
	int top;
	
	public:
	OperandStack(){top=-1;} //top을 -1로 초기화. 객체변수 top은 public이 아니기 때문에 함수로 초기화
	bool isEmpty(){return top==-1;} //비어있으면 top은 -1
	bool isFull(){return top == MAX_STACK_SIZE-1;} //가득차있으면 top은 배열 크기의 -1. 배열의 시작은 0부터기 때문에 맨 위가 배열크기-1임
	
	void push(double e){
		if(isFull())error("스택 포화 에러"); //가득하면 포화 에러
		data[++top]=e; //top하나 증가시키고 거기에 data를 push
	}
	double pop(){
		if(isEmpty())error("스택 공백 에러"); //pop을 했는데 비어있어서 빼낼 것이 없음. 공백 에러
		return data[top--]; //삭제하기 전 해당 데이터를 반환하고, 그 뒤에 top을 -1하기
	}
};

double calcPostfixExpr(FILE *fp = stdin){ //계산 함수
	char c;
	double val;
	
	OperandStack st; //객체 생성
	
	while((c=getc(fp))!='\n'){ //엔터전까지 string입력 받기
		if(c=='+'||c=='-'||c=='*'||c=='/'){ 
			//오퍼랜드 입력받다가 operator나오면 오퍼랜드를 전부 꺼내기위해 전부 pop
			//왜냐하면 후위표기는 숫자가 다 끝나면 그 뒤에 연산자가 나오기 때문
			
			double val2 = st.pop(); //오퍼랜드 하나 꺼내서 값 저장
			double val1 = st.pop(); //남은 오퍼랜드 값 저장
			switch(c){ //입력받은 연산자에 따라 value 계산하고 stack(배열)에 저장
				case '+': st.push(val1+val2); break;
				case '-': st.push(val1-val2); break;
				case '*': st.push(val1*val2); break;
				case '/': st.push(val1/val2); break;
			}
		}
		else if(c>='0'&&c<'9'){ //연산자가 아니라 아직 숫자면
			ungetc(c,fp); 
			//마지막 읽은 문자 반환(마지막으로 읽어 들인 위치로 읽기 위치를 되돌려 준다)
			//ungetc()를 사용하면 fgetc()로 읽어 들인 문자 하나를 반환하고, 파일 읽기 위치도 되돌아감
			fscanf(fp,"%lf",&val); //숫자를 val에 저장
			st.push(val); //val을 stack에 push
		}
	}
	return(st.pop()); //최종 계산한 값을 pop
}

int main(){
	printf("수식 입력 (Posfix)= ");
	double res = calcPostfixExpr();
	printf("계산 결과 => %f\n",res);
	
	return 0;
}