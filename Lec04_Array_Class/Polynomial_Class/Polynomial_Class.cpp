#include <iostream>
using namespace std;

class Polynomial {
private:
    int coef[5]; // 최대 4차

public:
    Polynomial(int c0, int c1, int c2, int c3, int c4) {
        coef[0] = c0;
        coef[1] = c1;
        coef[2] = c2;
        coef[3] = c3;
        coef[4] = c4;
    }

    void print() {
        for (int i = 4; i >= 0; i--) {
            if (coef[i] != 0) {
                cout << coef[i] << "x^" << i;
                if (i != 0) cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p(1, 2, 3, 0, 5); // 5x^4 + 3x^2 + 2x + 1
    p.print();
}