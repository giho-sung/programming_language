#include <fstream>
#include <iostream>
#include <string>

int main () {
    std::ifstream in("test.txt");
    char buf[100];

    if(!in.is_open()) {
        std::cout << "There is no file!" << std::endl;
        return 0;
    }

    std::string s;
    while (in) {
        getline(in, s);
        std::cout << s << std::endl;
    }

    return 0;
}