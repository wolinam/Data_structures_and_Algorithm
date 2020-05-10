#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

class Student
{
	int id; //private
	char name[MAX_STRING];
	char major[MAX_STRING];

public:
	Student(int i=0, char* name1=NULL,char* major1 = NULL){ //초기화
		set(i,name1,major1);
	}
	void set(int i, char* name1, char* major1){ //private의 변수값 설정하는 함수
		id = i;
		strcpy(name,name1);
		strcpy(major,major1);
	}
	void display(){//DATA인 STUDENT 출력 함수
		printf("ID:%-15d Name:%-10s Major:%-20s\n",id,name,major);
	}
};

class Node : public Student //상속
{
	Node* link;
	public:
	Node(int id=0, char* name1=NULL,char* major1=NULL) //생성자. 초기화
		: Student(id, name1, major1){link = NULL;}
	~Node(void){}//파괴자
	
	Node* getLink(){ 
		//현재 가리키는 link값(top의 아래에있는 node의 주소)을 가져옴
		//그래서 pop했을 때 새로운 top으로 지정
		return link;
	}
	void setLink(Node* p){
		//새로 들어온 node의 link값이 아래에 있는 node를 가리키도록 세팅
		link = p;
	}
};



class LinkedStack
{
	Node* top; //헤드포인터
public:
	LinkedStack(){top=NULL;}//생성자
	~LinkedStack(){while(!isEmpty()) delete pop();} //파괴
	bool isEmpty(){return top==NULL;}
	
	void push(Node* n){
		if(isEmpty())top=n; //비어있으면 입력받은 NODE를 top으로
		else{
			n->setLink(top);//무언가 있으면 새로 들어온 node의 link가 밑에 있는 node를 가리키도록 설정
			top=n; //입력받은 n을 top으로
		}
	}
	Node* pop(){
		if(isEmpty()) return NULL;
		Node* n = top; //맨 위에 있는 top을 현재의 n으로 설정
		top = top->getLink();//아래에 위치한 node의 주소값을 받아와서 새로운 top으로 설정
		return n ;//top내보냄
	}
	Node* peek(){return top;}
	
	void display(){
		printf("[LinkedStack]\n");
		for(Node *p = top; p!=NULL;p=p->getLink())
			p->display();
		printf("\n");
	}
	
};

int main()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, "Jack", "CS"));
	stack.push(new Node(2015130100, "Paul", "ME"));
	stack.push(new Node(2015130135, "Tim", "EE"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
	
	return 0;
}
