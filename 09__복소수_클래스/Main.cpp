#include <iostream>
using namespace std;
class Complex{
	public:
	int real;
	int imag;
	
	Complex(int r, int i){
		real = r;
		imag = i;
	}
	Complex(){
		real = 0;
		imag = 0;
	}

	void print(){
		if(real==0||imag==0)
			cout<<"";
		else if(imag<0)
			cout << "("<< real << imag<<"i)";
		else
			cout << "("<< real << "+" << imag << "i)";
	}
	
	void add( Complex a, Complex b){
		if(a.imag+b.imag<0)
			cout << "("<< a.real + b.real << a.imag+b.imag << "i)";
		else
			cout << "("<<a.real + b.real << "+" << a.imag+b.imag << "i)";
	}
};

int main()
{
    Complex a(7, 8);
    a.print();
    cout << "+";
    Complex b(2, 9);
    b.print();
    cout << "=";
    Complex c;
    c.add(a, b);
    c.print();
    cout << endl;

    Complex d(5, 3);
    d.print();
    cout << "+";
    Complex e(3, -4);
    e.print();
    cout << "=";
    Complex f;
    f.add(d, e);
    f.print();
    cout << endl;


    return 0;
}
