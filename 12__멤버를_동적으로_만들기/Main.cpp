#include <iostream>
using namespace std;

class Dog{
	private:
	int *pWeight;
	int *pAge;
	
	public:
	Dog(){
		pAge = new int(1);
		pWeight = new int(10);
	}
	~Dog(){
		delete pAge;
		delete pWeight;
	}
	
	int getAge(){return *pAge;} //private라서 함수 사용
	void setAge(int age){*pAge=age;} //멤버함수
	int getWeight(){return *pWeight;}
	void setWeight(int weight){*pWeight=weight;}
};

int main(){
	Dog *pDog = new Dog;
	cout << "강아지의 나이: " <<pDog->getAge()<<endl;
	
	pDog->setAge(5);
	cout<<"강아지의 나이: "<< pDog->getAge()<<endl;
	
	delete pDog;
	return 0;
}
