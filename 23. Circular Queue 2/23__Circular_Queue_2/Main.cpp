#pragma once
#include <stdio.h>
#include <stdlib.h>

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	10

class CircularQueue
{
protected:
	int	front;
	int	rear;
	int	data[MAX_QUEUE_SIZE];
public:
CircularQueue(){
	front=rear=0;
}
~CircularQueue(){}
int lastOP=0;
bool isEmpty(){
	return (lastOP==0)&&front==rear;
}//enq후 같으면 공백

bool isFull(){
	return (lastOP==1)&&((front)==(rear)%MAX_QUEUE_SIZE);
}//deq후 같으면 포화

void enqueue(int val){
	if(isFull())
		data[rear]=data[rear];

	else{
		data[rear]=val;
		rear = (rear+1)%MAX_QUEUE_SIZE;
		lastOP = 1;
		//data[rear]=val;
	}
}

int dequeue(){
	if(isEmpty())
		error(" Error : 큐가 공백상태입니다\n");
	else{
		front=(front+1)%MAX_QUEUE_SIZE;
		lastOP = 0;
		return data[front];
	}
}
int peek(){
	if(isEmpty())
		error(" Error: 큐가 공백상태입니다\n");
	else
		return data[(front+1)%MAX_QUEUE_SIZE];
}

	void display(){
		printf("큐 내용 : ");
		int maxi=(front<rear)?rear:rear+MAX_QUEUE_SIZE;
		for(int i = front;i<maxi;i++)
			printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};//class CircularQueue 끝



int main()
{
	CircularQueue que;
	for (int i = 1; i < 15; i++)
		que.enqueue(i);
	que.display();
	for (int i = 1; i < 6; i++) 
		que.dequeue();
	que.display();
	for (int i = 1; i < 15; i++)
		que.enqueue(i);		
	que.display();

	return 0;
}
