#pragma once
#include <stdio.h>

class Node
{
protected:
	int		id;		
	Node*	link;	
public:
	Node( int i, Node *l=NULL ) : id(i), link(l) { }
	~Node(void) { 
		if( link != NULL )
			delete link;
	}
	int	  getId()			{ return id; }
	Node* getLink()			{ return link; }
	void setLink(Node* l)	{ link = l; }
};

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class ArrayStack
{
	int		data[MAX_STACK_SIZE];	
	int		top;					

public:
	ArrayStack() { top = -1; }	
	~ArrayStack(){}				
	bool isEmpty() { return top == -1; }
	bool isFull()  { return top == MAX_STACK_SIZE-1; }

	void push ( int e ) {		
		if( isFull() ) error ("스택 포화 에러");
		data[++top] = e;
	}

	int pop ( ) {				
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top--];
	}

	int peek ( ){				
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top];
	}

	void display ( ) {			
		printf("[스택 항목의 수 = %2d] ==> ", top+1) ;
		for (int i=0 ; i<=top ; i++ )
			printf("<%2d>", data[i]);
		printf("\n");
	}
};


#define MAX_VTXS	256

class AdjListGraph
{
protected:
	int		size;				
	char	vertices[MAX_VTXS];	
	Node*	adj[MAX_VTXS];		

public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void){ reset(); }

	void reset(void) { 
		for( int i=0 ; i<size ; i++ ) 
			if( adj != NULL ) delete adj[i];
		size = 0;
	}
	bool isEmpty()			{ return (size==0); }
	bool isFull()			{ return (size>=MAX_VTXS); }
	char getVertex(int i)	{ return vertices[i]; }

	void insertVertex( char val ) {	
		if( !isFull() ) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}

	void insertEdge( int u, int v) {	
		adj[u] = new Node (v, adj[u]);	
	}

	void display( ) {
		printf("%d\n", size);				
		for( int i=0 ; i<size ; i++ ) {		
			printf("%c  ", getVertex(i));	

			for( Node *v=adj[i] ; v != NULL ; v=v->getLink() )
				printf("   %c", getVertex(v->getId()) );
			printf("\n");
		}
	}

};
class TopoSortGraph:public AdjListGraph{
	public:
	TopoSortGraph(void){}
	~TopoSortGraph(void){}
	void insertDirEdge(int u, int v){
		adj[u]=new Node(v,adj[u]);
	}
	void TopoSort(){
		ArrayStack s;
		int* inDeg = new int[size];
		for(int i=0;i<size;i++)
			inDeg[i]=0;
		for(int i = 0; i<size;i++){
			Node*node=adj[i];
			while(node!=NULL){
				inDeg[node->getId()]++;
				node=node->getLink();
			}
		}
		
		for(int i = 0;i<size;i++)
			if(inDeg[i]==0)s.push(i);
		
		while(s.isEmpty()==false){
			int w = s.pop();
			printf(" %c",getVertex(w));
			Node* node=adj[w];
			while(node!=NULL){
				int u = node->getId();
				inDeg[u]--;
				if(inDeg[u]==0)
					s.push(u);
				node=node->getLink();
				
			}
		}
		printf("\n");
		delete[]inDeg;
	}
};





int main()
{
	TopoSortGraph g;

	for( int i=0 ; i<6 ; i++ )
		g.insertVertex( 'A'+i );

	g.insertDirEdge( 0, 2 );
	g.insertDirEdge( 0, 3 );

	g.insertDirEdge( 1, 3 );
	g.insertDirEdge( 1, 4 );

	g.insertDirEdge( 2, 3 );
	g.insertDirEdge( 2, 5 );

	g.insertDirEdge( 3, 5 );

	g.insertDirEdge( 4, 5 );

	printf("Topology Sort:\n");

	g.TopoSort( );
	
	return 0;
}


