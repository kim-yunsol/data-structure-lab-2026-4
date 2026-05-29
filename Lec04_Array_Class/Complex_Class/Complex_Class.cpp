#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex A(2.0, 3.1);
    Complex B(5.4, 1.2);

    cout << "A = ";
    A.print();

    cout << "B = ";
    B.print();

    Complex C = A.add(B);

    cout << "A + B = ";
    C.print();
}