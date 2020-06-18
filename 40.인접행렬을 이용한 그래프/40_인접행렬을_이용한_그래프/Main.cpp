#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_VTXS	256

class AdjMatGraph{
	protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
	
	public:
	AdjMatGraph(){reset();}
	~AdjMatGraph(){}

	char getVertex(int i){return vertices[i];}
	int getEdge(int i, int j){return adj[i][j];}
	void setEdge(int i, int j, int val){adj[i][j]=val;}
	bool isEmpty(){return (size == 0);}
	bool isFull(){return (size>=MAX_VTXS);}
	
	void reset(){
		size = 0;
		for(int i = 0; i<MAX_VTXS;i++)
			for(int j = 0; j<MAX_VTXS;j++)
				setEdge(i,j,0);
	
	}
	void insertVertex(char name){
		if(!isFull())vertices[size++]=name;
		else printf("Error: 그래프 정점의 개수 초과\n");
	}
	
	void insertEdge(int u, int v){
		setEdge(u,v,1);
		setEdge(v,u,1);
	}
	void display(FILE* fp = stdout){
		fprintf(fp,"%d\n",size);
		for(int i = 0; i<size;i++){
			fprintf(fp,"%c  ",getVertex(i));
			for(int j = 0; j<size;j++)
				fprintf(fp," %3d",getEdge(i,j));
			fprintf(fp,"\n");
		}
	}
};

int main()
{
	AdjMatGraph g;
	
	for( int i=0 ; i<4 ; i++ )
		g.insertVertex( 'A'+i );

	g.insertEdge(0,1);
	g.insertEdge(0,3);
	g.insertEdge(1,2);
	g.insertEdge(1,3);
	g.insertEdge(2,3);
	printf("인접 행렬로 표현한 그래프\n");
	g.display();

	return 0;

}

