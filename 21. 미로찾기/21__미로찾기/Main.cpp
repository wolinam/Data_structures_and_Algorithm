#include "stdio.h"
#include <stack>
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

struct Location2D {
//Location2D 클래스 작성
int row;
int col;
Location2D(int r=0,int c=0){
	row = r;
	col = c;
} //초기화함수
};//struct Location2D 끝

bool isValidLoc( int r, int c )
{
	if( r < 0 || c < 0 || r>=MAZE_SIZE || c>=MAZE_SIZE ) return false;
	else return map[r][c] == '0' || map[r][c] == 'x' ;
}//bool isValidLoc( int r, int c ) 끝


int main()
{
	stack<Location2D> locStack;				
	Location2D entry(1,0);	
	locStack.push( entry );					
//필요코드 작성
while(locStack.empty()==false){
	Location2D here = locStack.top(); // here라는 구조체에 top의 값 저장
	locStack.pop(); //이동
	
	int r = here.row;
	int c = here.col;
	printf("(%d,%d)",r,c); //현재위치 출력
	if(map[r][c]=='x'){ //현재위치가 도착지점이면 성공
		printf("미로 탐색 성공");
		return 0 ;
	}
	else{
		map[r][c]='.';//이미 방문한 곳 표시
		if(isValidLoc(r-1,c))
			locStack.push(Location2D(r-1,c));
		if(isValidLoc(r+1,c))
			locStack.push(Location2D(r+1,c));
		if(isValidLoc(r,c+1))
			locStack.push(Location2D(r,c+1));
		if(isValidLoc(r,c-1))
			locStack.push(Location2D(r,c-1));
	}
}

	return 0 ;
}//int main() 끝

