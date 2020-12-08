#include <string.h>
#include <iostream>

class Test {
    char c;

    public:
        Test(char _c) {
            c = _c;
            std::cout << "call constructor " << c << std::endl;
        }
        ~Test() { std::cout << "call destuctor " << c << std::endl; }

};

void simple_function() { 
    Test b('b'); 
    Test* e = new Test('e');
}

int main() {
    Test a('a');
    simple_function();
}