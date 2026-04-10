#include <iostream>
using namespace std;

class Car {
protected:
    int speed;

public:
    Car() {
        speed = 0;
    }

    void setSpeed(int s) {
        speed = s;
    }

    void showSpeed() {
        cout << "Speed: " << speed << endl;
    }
};

class SportsCar : public Car {
public:
    void turbo() {
        speed += 50;
    }
};

int main() {
    SportsCar car;

    car.setSpeed(100);
    car.showSpeed();

    car.turbo();
    car.showSpeed();
}