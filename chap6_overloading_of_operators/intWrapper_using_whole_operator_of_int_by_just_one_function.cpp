#include <iostream>

class Int {
    int data;
    

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}

    // main function!
    // using all the operation of int
    // here, operator function returns which one is processed
    // But, there is no return type.
    operator int() {return data;}
};

int main() {
    Int x = 3;
    int a = x + 4;
    int b = 3;

    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(a * 2 + x + 4).name() << std::endl;
    x = a * 2 + x + 4;
    std::cout << x << std::endl;
}

