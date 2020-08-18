#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define MAX_LIST_SIZE 100
using namespace std;

inline void error(char* str){
	fprintf(stderr,"%s\n",str);
	exit(1);
};

class ArrayList{
	int data[MAX_LIST_SIZE];
	int length;
	public:
	ArrayList(void){length=0;} //생성자 및 length 초기화
	
	void insert(int pos, int e){ //pos위치에 item e를 삽입
		if(!isFull()&&pos>=0&&pos<=length){ //가득차지 않았고, index가 0부터 length안에 있으면
			//맨끝에 삽입할 수도 있으므로 length에 등호 들어가도 됨
			for(int i=length;i>pos;i--) //끝에서부터 한칸씩 뒤로 미룸
				data[i] = data[i-1];
			data[pos]=e;
			length++;
		}
		else error("포화상태 오류 또는 삽입 위치 오류"); //에러처리
	}
	
	void remove(int pos){
		if(!isEmpty()&&0<=pos&&pos<length){
			//length위치에는 이미 삭제할 것이 없음. 그러므로 등호 들어가지 않음.
			//length는 맨 마지막 data의 한 칸 뒤에 위치함
			for(int i=pos+1;i<length;i++) //삭제할 요소의 다음것부터 마지막요소까지 아ㅠ으로 당김
				data[i-1]=data[i];
			length--;
		}
		else error("공백상태 오류 또는 삭제 위치 오류");
	}
	
	int getEntry(int pos){return data[pos];} //값 호출
	
	bool isEmpty(){return length==0;}
	bool isFull(){return length==MAX_LIST_SIZE;}
	
	bool find(int item){
		for(int i = 0;i<length;i++)
			if(data[i]==item)return true;
		return false;
	}
	void replace(int pos, int e){
		data[pos]=e;
	}
	int size(){return length;}
	void display(){
		printf("[# of elements in the list = %2d]:",length);
		for(int i =0;i<length;i++)
			printf("[%2d]",data[i]);
		printf("\n");
	}
	void clear(){length=0;}
};



int main()
{
	ArrayList list;					

	list.insert( 0, 10 );			
	list.insert( 0, 20 );			
	list.insert( 1, 30 );			
	list.insert(list.size(),40 );	
	list.insert( 2, 50 );			
	list.display();					
	cout<<"the value of index 2 : "<< list.getEntry(2) <<endl;
	list.replace(0,100);
	list.display();					
	

	list.remove( 2 );				
	list.remove(list.size()-1);		
	list.remove(0);					
	list.replace(1, 90);			
	list.display();					

	list.clear();					
	list.display();					
	
	return 0;
}