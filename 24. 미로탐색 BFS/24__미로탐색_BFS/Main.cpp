#pragma once
#include "stdio.h"
#include <queue>
using namespace std;


const	int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};
bool isValidLoc(int r, int c){ //오류
	if(r<0||c<0||r>=MAZE_SIZE||c>=MAZE_SIZE) return false;
	else return map[r][c]=='0'||map[r][c]=='x'; //아니면 위치한 곳이 0이나 x일 때 true 반환
}
struct Location2D{
	int row;
	int col;
	Location2D(int r=0,int c=0){row =r;col=c;} //초기화함수
	bool isNeighbor(Location2D &p){ //이웃한 곳인지 파악
		return((row==p.row&&(col==p.col-1||col==p.col+1))||(col==p.col&&(row==p.row-1||row==p.row+1)));
	}
	bool operator==(Location2D&p){return row == p.row&&col==p.col;} //현재위치
};

int main(){
	queue<Location2D>locQueue; //템플릿
	Location2D entry(1,0); //시작위치 넣음
	locQueue.push(entry); //시작위치로 이동
	
	while(locQueue.empty()==false){ //큐가 비어있기 전까지
		Location2D here = locQueue.front(); //현재위치는 큐의 맨앞
		locQueue.pop();
		
		int r = here.row; //현재위치
		int c = here.col;
		printf("(%d,%d)",r,c);
		
		if(map[r][c]=='x'){//도착
			printf("success\n");
			return 0;
		}
		else{ //이웃한 곳
			map[r][c]='.'; //현재위치 다시 안넣도록 .으로 바꿈
			if(isValidLoc(r-1,c)) locQueue.push(Location2D(r-1,c));
			if(isValidLoc(r+1,c)) locQueue.push(Location2D(r+1,c));
			if(isValidLoc(r,c-1)) locQueue.push(Location2D(r,c-1));
			if(isValidLoc(r,c+1)) locQueue.push(Location2D(r,c+1));
		}
	}
	printf("fail\n");
	return 0;
}