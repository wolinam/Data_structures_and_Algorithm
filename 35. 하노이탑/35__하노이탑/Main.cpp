#include <cstdio> /* C 헤더파일 <stdio.h>을 포함하는 것과 동일 */
void hanoiTower(int n, char from, char tmp, char to){
	if(n==1)printf("원판 1을 %C에서 %C으로 옮긴다.\n",from,to);
	else{
		hanoiTower(n-1,from,to,tmp);
		printf("원판 %d을 %C에서 %C으로 옮긴다.",n,from,to);
		hanoiTower(n-1,tmp,from,to);
	}
}







int main()
{
		 int n=7;
		 printf("A,B,C 세개의 기둥이 있고, 모두 %d개의 원판이 있습니다.\n",n);
	
     hanoiTower(7, 'A', 'B', 'C');
		return 0;
}
