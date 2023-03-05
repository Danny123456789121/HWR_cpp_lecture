#include <iostream>

class Flash {
public:
    Flash(int blitzanzahl) : blitzanzahl(blitzanzahl) {}

    int getBlitzanzahl() const { return blitzanzahl; }
    void setBlitzanzahl(int blitzanzahl) { this->blitzanzahl = blitzanzahl; }

    void toString() {
        std::cout << "Blitzanzahl: " << blitzanzahl << std::endl;
    }

    private:
    int blitzanzahl;
};


int test() {

    int *test = new int(5);
    int age = 5;
    int &ageRef = age;
    int& ageRef2 = age;

    ageRef =10;



    Flash *ref = new Flash(5);


    std::cout << "Ref: " << ref->getBlitzanzahl() << std::endl;
    std::cout << "Ref: " << (*ref).getBlitzanzahl() << std::endl;
    std::cout << "Test: " << test << std::endl;
    std::cout << "Age: " << &ageRef << std::endl;
    std::cout << "Age: " << &age << std::endl;

    std::cout << "Age: " << &ageRef2 << std::endl;



    return 0;
}
