#include <stdio.h>// 코딩하시오.
#include <stdlib.h>

inline void error(char*str){
	fprintf(stderr,"%s\n",str);
	exit(1);
}

#define MAX_QUEUE_SIZE 100

class CircularQueue{
	protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
	
	public:
	CircularQueue(){
		front=rear=0;
	}
	~CircularQueue(){}
	
	bool isEmpty(){return front == rear;}
	bool isFull(){return (rear+1)%MAX_QUEUE_SIZE==front;}
	
	//rear 하나 증가
	void enqueue(int val){
		if(isFull()) //넣어야하므로 포화인지 확인
			error(" error: 큐가 포화상태입니다\n");
		else{
			data[rear]=val;
			rear = (rear+1)%MAX_QUEUE_SIZE;
			//data[rear] = val;
		}
	}
	//front값 증가
	int dequeue(){
		if(isEmpty()) //삭제해야하므로 공백인지 확인
			error(" Error: 큐가 공백상태입니다\n");
		else{
			front=(front+1)%MAX_QUEUE_SIZE;
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
		//rear가 한바퀴를 돌았는지 안돌았는지 체크
		for(int i = front;i<maxi;i++)
			printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};

int main(){
	CircularQueue que; //객체 생성
	for(int i=1;i<10;i++)
		que.enqueue(i);
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
	
	return 0;
}