#include <iostream>
using namespace std;

class Pizza {
public:
	Pizza(int s) : size(s) { }
	int size;			// 단위: 인치
	
	void makeDouble();
};

void Pizza::makeDouble()
{
	size *= 2;
}

int main()
{
	Pizza pizza(10);
	pizza.makeDouble();
	cout << pizza.size << "인치 피자" << endl;
	return 0;
}