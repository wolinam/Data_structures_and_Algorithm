#include <iostream>
using namespace std;

class Node{
	public:
	char m;
	Node *link;
	Node(char a=NULL){ //초기화
		m = a;
		link = NULL;
	}
	void insertNext(Node *nextNode){
		nextNode->link=link;
		link=nextNode;
	}
	void insertFront(Node *frontNode){
		frontNode->link=link;
		link=frontNode;
	}
	void removeNext(){
		if(link!=NULL) link=link->link;
	}
	void display(){
		Node *p = link;
		while(p!=NULL){
			cout<<p->m<<" ";
			p=p->link;
		}
		cout<<endl;
	}
};

int main(){
	Node head;
	head.insertNext(new Node('a'));
	head.link->insertNext(new Node('b'));
	head.link->link->insertNext(new Node('c'));
	
	head.insertFront(new Node('d'));
	head.insertFront(new Node('e'));
	head.insertFront(new Node('f'));
	head.display();
	
	head.removeNext();
	head.display();
	head.link->link->insertNext(new Node('g'));
	head.link->link->insertFront(new Node('h'));
	head.display();
	
	return 0;
}