#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL = 2;

int main() {

    deque<Car> line;

    // Add initial cars 
    for (int i = 0; i < INITIAL; ++i) {
        line.push_back(Car());
    }

    cout << "Inital line of cras:\n";
    for (int i = 0; i <= line.size(); i++) {
        line[i].ptint();
    }
    return 0;
}