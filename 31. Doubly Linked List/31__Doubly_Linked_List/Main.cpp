#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

//class Node2
class Node2{
	Node2* prev;
	Node2* next;
	int data;
	public:
	Node2(int val=0) : data(val), prev(NULL), next(NULL){}
	Node2* getPrev(){return prev;}
	Node2* getNext(){return next;}
	void setPrev(Node2* p){prev=p;}
	void setNext(Node2* n){next=n;}
	void display(){printf(" <%2d>",data);}
	bool hasData(int val){return data==val;}
	
	void insertNext(Node2 *n){
		if(n!=NULL){
			n->prev=this;
			n->next=next;
			if(next!=NULL) next->prev=n;
			next=n;
		}
	}
	Node2* remove(){
		if(prev!=NULL) prev->next=next;
		if(next!=NULL) next->prev=prev;
		return this;
	}
};



//class DblLinkedList
class DblLinkedList{
	Node2 org;
	public:
	DblLinkedList():org(0){}
	~DblLinkedList(){while(!isEmpty()) delete remove(0);}
	Node2* getHead(){return org.getNext();}
	bool isEmpty(){return getHead()==NULL;}
	
	Node2* getEntry(int pos){
		Node2* n=&org;
		for(int i =-1;i<pos;i++,n=n->getNext())
			if(n==NULL) break;
		return n;
	}
	
	void insert(int pos, Node2 *n){
		Node2* prev=getEntry(pos-1);
		if(prev!=NULL)
			prev->insertNext(n);
	}
	
	Node2* remove(int pos){
		Node2* n=getEntry(pos);
		return n->remove();
	}
	
	void replace(int pos, Node2* n){
		Node2* prev=getEntry(pos-1);
		if(prev!=NULL){
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}
	
	int size(){
		int count = 0;
		for(Node2 *p = getHead(); p!=NULL; p=p->getNext())
			count++;
		return count;
	}
	
	void display(){
		printf("[ the size of the doubly linked list = %2d] : ",size());
		for(Node2* p=getHead();p!=NULL;p=p->getNext())
			p->display();
		printf("\n");
	}
	
	void clear(){while(!isEmpty()) delete remove(0);}
};





int main()
{
	DblLinkedList	list;				// 새로운 리스트 객체 list를 만듦

	list.insert( 0, new Node2(10) );		// 리스트 맨 앞에 10 삽입
	list.insert( 0, new Node2(20) );		// 리스트 맨 앞에 20 삽입
	list.insert( 1, new Node2(30) );		// 리스트 1위치에 30 삽입
	list.insert( list.size(), new Node2(40) );	// 리스트 마지막에 40 삽입
	list.insert( 2, new Node2(50) );		// 리스트 1위치에 50 삽입
	list.display();						// 리스트내용 화면출력

	list.remove( 2 );					// 리스트 2위치의 항목 삭제
	list.remove(list.size()-1);			// 리스트 마지막 항목 삭제
	list.remove(0);						// 리스트 맨 앞 항목 삭제
	list.replace(1, new Node2(90));		// 리스트의 1위치 항목 값 변경
	list.display();						// 리스트내용 화면출력
	
	list.clear();						// 리스트의 모든 항목 삭제
	list.display();						// 리스트내용 화면출력
	
	return 0;
}


