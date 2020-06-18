#include <stdio.h>
#include <stdlib.h>
#pragma once

// class Node 구현
class Node{
	Node* link;
	int data;
	public:
	Node(int val=0):data(val),link(NULL){} //생성자 및 초기화
	Node* getLink(){return link;}//반환형이 노드포인터인 getlink함수
	//현재 가리키는 link의 값을 반환함
	void setLink(Node* next){link=next;}
	//다음 노드가 가리키는 link를 인자로 받음
	//그 link가 현재 노드의 link가 됨
	void display(){printf(" <%2d>",data);}
	bool hasData(int val){return data == val;} //값이 있는지 확인
	
	void insertNext(Node *n){ //삽입연산
		if(n!=NULL){
			n->link=link; //현재 노드가 가리키는 link를 새로 들어온 노드가 가리킴
			link=n; //현재 노드의 link는 새로 삽입된 것을 가리킴
		}
	}
	
	Node* removeNext(){ //반환형이 node*임. node를 반환함
		Node* removed = link;
		//현재 노드가 가리키는 것, 즉 다음 노드가 removed라는 이름의 노드
		if(removed != NULL)
			link = removed ->link; //현재 노드가 가리키는 다음노드는 삭제될 것이므로 다음노드가 가리키는 link의 값을 현재노드의 link로 설정
		return removed; //삭제한 노드를 반환함
	}
};


// class LinkedList 구현
class LinkedList{
	Node org; //객체생성
	public:
	LinkedList():org(0){} //생성자
	~LinkedList(){clear();} //파괴자
	void clear(){while(!isEmpty()) delete remove(0);}
	//isEmpty가 될 때까지 헤드를 삭제함
	Node* getHead(){return org.getLink();}
	//현재 노드가 가리기는 link값을 반환함
	bool isEmpty(){return getHead()==NULL;}
	
	Node* getEntry(int pos){
		Node* n = &org;
		for(int i = -1; i<pos;i++,n=n->getLink())
			if(n==NULL) break;
		return n;
	}
	
	void insert(int pos, Node *n){
		Node* prev  = getEntry(pos-1);
		if(prev!=NULL)
			prev -> insertNext(n);
	}
	
	Node* remove(int pos){
		Node* prev = getEntry(pos-1);
		return prev->removeNext();
	}
	/*삽입하고 다음것을 삭제하려면?
	Node* replace(int pos, Node *n){
		Node* prev = getEntry(pos-1);
		Node* preev = getEntry(pos);
		if(prev!=NULL){
			prev -> insertNext(n);
			//delete preev->removeNext();
		}
		return preev->removeNext();
	}*/
	
	void replace(int pos, Node *n){
		Node* prev = getEntry(pos-1);
		if(prev!= NULL){
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	
	int size(){
		int len = 0;
		//while(getHead()!=NULL){
		for(Node* p = getHead(); p!=NULL; p=p->getLink())
			len++;
		return len;
	}
	
	void display(){
		printf("[ the size of the linked list = %2d] : ",size());
		for(Node *p = getHead(); p!=NULL; p=p->getLink())
			p->display();
		printf("\n");
	}
};



int main()
{
	LinkedList	list;				

	list.insert( 0, new Node(10) );	
	list.insert( 0, new Node(20) );	
	list.insert( 1, new Node(30) );	
	list.insert( list.size(), new Node(40) );
	list.insert( 2, new Node(50) );	
	list.display();			
	list.replace(1,new Node(80)) ;
	list.display();			

	list.remove( 2 );		
	list.remove(list.size()-1);		
	list.remove(0);					
	list.replace(1, new Node(90));	
	list.display();					

	list.clear();					
	list.display();					
	
	return 0;
}


