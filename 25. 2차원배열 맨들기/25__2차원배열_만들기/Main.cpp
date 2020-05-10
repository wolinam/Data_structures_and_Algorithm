#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int** alloc2DInt(int a, int b);
void free2DInt(int** mat, int rows, int cols);
void print2DInt(int** mat, int rows, int cols);
int** set2D(int** mat, int rows, int cols);

int main(){
	int **mat;
	class Matsize{
		public:
		int row,col;
		Matsize(int r=0,int c=0){
			row = r;
			col = c;
		} //0으로 초기화
		void setSize(int r, int c){
			row = r;
			col = c;
		} //size setting
	};
	Matsize s[4]; //4개의 배열 생성 -> 그런데 왜 [4]? 배열안에 이차원 배열을 넣는건가...?
	s[0].setSize(3,4);
	s[1].setSize(7,10);
	s[2].setSize(12,6);
	s[3].setSize(16,8);
	
	for(int i = 0;i<4;i++){ //배열 4개 출력
		printf("%d row %d col \n\n\n",s[i].row,s[i].col);//어떤 배열인지 출력
		mat = alloc2DInt(s[i].row,s[i].col);//동적할당
		set2D(mat,s[i].row,s[i].col);
		print2DInt(mat,s[i].row,s[i].col);//출력
		free2DInt(mat,s[i].row,s[i].col);//배열삭제
		cout << endl;
	}
	return 0;
}
void print2DInt(int **mat,int rows, int cols){
	//if(rows<=0||cols<=0) return NULL;
	for(int i = 0; i<rows;i++){
		for(int j = 0;j<cols;j++)
			printf("%4d",mat[i][j]);
		printf("\n");
	}
}

int** set2D(int **mat, int rows, int cols){ //값 설정
	if(rows<=0||cols<=0) return NULL;
	for(int i = 0;i<rows;i++){
		for(int j=0;j<cols;j++)
			mat[i][j]=(i+1)*(j+1);
	}
	return mat;
}

int**alloc2DInt(int rows, int cols){ //동적할당함수
	if(rows<=0||cols<=0) return NULL; //오류처리
	int **mat = new int*[rows];  //행 동적할당
		for(int i =0; i<rows; i++) //각 행마다 열 동적할당
			mat[i]=new int[cols];
	return mat;
}
void free2DInt(int** mat,int rows, int cols){ //애초에 처음부터 col 삭제...?
	cols = 0;
	if(mat!=NULL){
		for(int i =0;i<rows;i++) //모든 행에 대해 for문으로 전부 삭제
			delete[]mat[i];
		delete[]mat; //배열 자체 삭제
	}
}