#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
	Node* link;
	int data;
	
	public:
	Node(int val=0):data(val),link(NULL){}//생성자, 초기화
	Node* getLink(){
		return link;
	}
	void setLink(Node* next){
		link=next;
	}
	void display(){
		printf(" <%2d>",data);
	}
};

class LinkedQueue{
	Node* front;
	Node* rear;
	
	public:
	LinkedQueue(){front=rear=NULL;}
	~LinkedQueue(){while(!isEmpty()) delete dequeue();}
	bool isEmpty(){return front==NULL;}
	
	void enqueue(Node *p){
		if(isEmpty()) front=rear=p;
		else{
			rear->setLink(p); //새로 들어온 곳의 link는 NULL
			rear=p; //새로 들어온 p가 이제 rear
		}
	}
	Node* dequeue(){
		if(isEmpty()) return NULL;
		Node* p = front;
		front = front->getLink();
		return p;
	}
	void display(){
		printf("Q: ");
		for(Node *p=front;p!=NULL;p=p->getLink())
			p->display();
		printf("\n");
	}
};


int main()
{
	LinkedQueue que;
	for( int i=1 ; i<10 ; i++ )
		que.enqueue( new Node(i) );
	que.display();

	que.dequeue()->display();	
	que.dequeue()->display();
	que.dequeue()->display();

	que.display();
	
	return 0;

}

