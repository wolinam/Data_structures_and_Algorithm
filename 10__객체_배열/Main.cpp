#include <iostream>
using namespace std;

class Circle{
	public:
	int x,y;//멤버변수
	int radius;
	
	Circle():x{0},y{0},radius{0}{}//디폴트 생성자
	Circle(int x, int y, int r):x{x},y{y},radius{r}{}
	
	void print(){
		cout<< "반지름: " <<radius<< " @(" <<x<< ", " <<y<< ")" <<endl;
	} //멤버함수
};

int main(void){
	Circle objArray[10]; //배열인 객체 생성
	
	for(Circle& c: objArray){ //objArray[10]에 대해서 변수 입력
		c.x = rand()%500;
		c.y = rand()%300;
		c.radius = rand()%100;
	}
	for(Circle c:objArray) //반복문을 통해 objArray 전부 출력
		c.print();
	
	return 0;
}