#include <iostream>
using namespace std;

class Dog{
	private:
	string name; //멤버변수
	int age;
	
	public:
	Dog(){ //생성자
		age = 1;
		name = "바둑이";
	}
	~Dog(){}//파괴자
	
	//함수 선언과 정의
	int getAge(){return age;}
	void setAge(int dog_age){age=dog_age;}
};

int main(){
	Dog *pDog = new Dog; //4바이트 공간을 만듦
	cout << "강아지의 나이: " << pDog->getAge() << endl;
	
	pDog->setAge(5);
	cout << "강아지의 나이: " << pDog->getAge() << endl;
	
	delete pDog;
	return 0;
}