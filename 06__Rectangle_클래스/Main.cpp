#include <iostream>
using namespace std;
class Rectangle{
	public:
	int w,h;
	int calcArea(){
		return w*h;
	}
};



int main()
{
	Rectangle r{ 3, 4 };

	cout << "사각형의 넓이 : " << r.calcArea() << '\n';
	return 0;
}