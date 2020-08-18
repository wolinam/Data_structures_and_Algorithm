#pragma once
#include <stdio.h>
#include <stdlib.h>

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CircularQueue
{
	int	front;					
	int	rear;					
	int	data[MAX_QUEUE_SIZE];	
public:
	CircularQueue()	{ front = rear = 0; }
	~CircularQueue() { }
	bool isEmpty()	{ return front == rear; }
	bool isFull()	{ return (rear+1)%MAX_QUEUE_SIZE == front; }
	void enqueue( int val ) {	
		if( isFull() )
			error("  error: 큐가 포화상태입니다\n");
		else {
			rear = (rear+1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue( ) {		
		if( isEmpty() )
			error("  Error: 큐가 공백상태입니다\n");
		else {
			front = (front+1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek( ){		
		if( isEmpty() )
			error("  Error: 큐가 공백상태입니다\n");
		else 
			return data[(front+1) % MAX_QUEUE_SIZE];
	}
	void display( ) {		
		printf( "큐 내용 : ");
		int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
		for( int i = front+1 ; i<=maxi ; i++ )
			printf( "[%2d] ", data[i%MAX_QUEUE_SIZE]);
		printf( "\n");
	}
};


#define MAX_VTXS	256

class AdjMatGraph
{
protected:
	int		size;						
	char	vertices[MAX_VTXS];			
	int		adj[MAX_VTXS][MAX_VTXS];	

public:
	AdjMatGraph( )				{ reset(); }
	~AdjMatGraph()				{  }

	char getVertex(int i)		{ return vertices[i]; }
	int	 getEdge(int i, int j)	{ return adj[i][j]; }
	void setEdge(int i, int j, int val)	{ adj[i][j] = val; }
	bool isEmpty()				{ return size==0; }
	bool isFull()				{ return size>=MAX_VTXS; }

	void reset() {
		size=0;
		for(int i=0 ; i<MAX_VTXS ; i++ )
		for(int j=0 ; j<MAX_VTXS ; j++ )
			setEdge(i,j,0);
	}

	void insertVertex( char name ) {
		if( !isFull() ) vertices[size++] = name;
		else printf("Error: 그래프 정점의 개수 초과\n");
	}

	void insertEdge( int u, int v ) {
		setEdge(u,v,1);
		setEdge(v,u,1);
	}

	void display( FILE *fp = stdout) {
		fprintf(fp, "%d\n", size);				
		for( int i=0 ; i<size ; i++ ) {			
			fprintf(fp,"%c  ", getVertex(i));	
			for( int j=0 ; j<size ; j++ )		
				fprintf(fp, " %3d", getEdge(i,j));
			fprintf(fp,"\n");
		}
	}
};
class SrchAMGraph:public AdjMatGraph{
	protected:
	bool visited[MAX_VTXS];
	
	public:
	void resetVisited(){
		for(int i = 0; i<size; i++)
			visited[i]=false;
		
	}
	bool isLinked(int u, int v){return getEdge(u,v)!=0;}
	
	void DFS(int v){
		visited[v]=true;
		printf("%c ",getVertex(v));
		
		for(int w=0;w<size;w++)
			if(isLinked(v,w)&&visited[w]==false)
				DFS(w);
	}
	void BFS(int v){
		visited[v]=true;
		printf("%c ",getVertex(v));
		CircularQueue que;
		que.enqueue(v);
		
		while(!que.isEmpty()){
			int v = que.dequeue();
			for(int w= 0;w<size;w++)
				if(isLinked(v,w)&&visited[w]==false){
					visited[w]=true;
					printf("%c ",getVertex(w));
					que.enqueue(w);
				}
		}
	}
};

class ConnectedComponentGraph:public SrchAMGraph{
	int label[MAX_VTXS];
	public:
	void labelDFS(int v , int color){
		visited[v]=true;
		label[v]=color;
		printf("%c ",getVertex(v));
		
		for(int w= 0 ;w<size;w++)
			if(isLinked(v,w)&&visited[w]==false)
				labelDFS(w,color);
	}
	void findConnectedComponent(){
		int count = 0;
		for(int i = 0; i<size; i++)
			if(visited[i]==false){
				labelDFS(i,++count);
			}
		printf("\n그래프 연결성분 개수 = = %d\n",count);
		for(int i=0;i<size;i++)
			printf("%c=%d ",getVertex(i),label[i]);
		printf("\n");
	}
};





















int main()
{
	ConnectedComponentGraph g;
	
	for( int i=0 ; i<5 ; i++ )
		g.insertVertex( 'A'+i );

	g.insertEdge(1,0);
	g.insertEdge(2,0);
	g.insertEdge(3,4);
	printf("연결 성분 테스트 그래프\n");
	g.display();

	g.resetVisited();
	g.findConnectedComponent( );
	
	return 0;
}