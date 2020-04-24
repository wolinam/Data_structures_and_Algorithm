//여기에 코딩해라.
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

class Student{
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
	public:
	Student(int i=0, char*nam="",char*dep=""){
		set(i,nam,dep);
	}
	void set(int i, char*nam, char*dep){
		id = i;
		strcpy(name, nam);
		strcpy(dept, dep);
	}
	void display(){ //class student 출력 함수
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id,name,dept);
	}
};

inline void error(char*str){ //inline??
	printf("%s\n",str); //출력함수
	exit(0);
};

class StudentStack{
	int top;
	Student data[MAX_STACK_SIZE];
	
	public:
	StudentStack(){top=-1;}
	~StudentStack(){} //?
	bool isEmpty(){return top == -1;} //bool?
	bool isFull(){return top == MAX_STACK_SIZE-1;}
	
	void push(Student e){
		if(isFull())error("스택 포화 에러");
		data[++top]=e;
	}
	Student pop(){
		if(isEmpty())error("스택 공백 에러");
		return data[top--];
	}
	Student peek(){
		if(isEmpty())error("스택 공백 에러");
	}
	void display(){
		printf("[전체 학생의 수 = %2d]\n",top+1);
		for(int i=0;i<=top;i++)
			data[i].display();
		printf("\n");
	}
};

int main(){
	StudentStack stack;
	stack.push(Student(1,"김아무개","전정공"));
	stack.push(Student(2,"박아무개","전정공"));
	stack.push(Student(3,"이아무개","컴공"));
	
	stack.display();
	stack.pop( );
	stack.display();
	stack.pop( );
	stack.display();
	stack.pop( );
	stack.display();
	stack.peek( );
	
	return 0;
}