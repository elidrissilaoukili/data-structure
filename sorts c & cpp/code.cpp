#include <iostream>

using namespace std;
// Base class (parent)
class Vehicle {
  public:
    void makeSound() {
      cout << "Sound of a vehicle"<<endl ;
    }
};

class Car {
    public:
        void speed(){
            cout << "max spped is 120";
        }
};

class Dacia : public Vehicle, public Car {
    public:

};

int main() {
  Dacia dacia;
  dacia.makeSound();
  dacia.speed();
  return 0;
}