#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in.seekg(0,std::ios::end); // move position pointer to end of file

        int size = in.tellg(); // read where the pointer is. it means size of the file

        s.resize(size); // allocate memory which fit in the size of the file

        in.seekg(0, std::ios::beg); // move position pointer to begin of the file

        in.read(&s[0], size); // read all of the file and save it in the string s
        std::cout << s << std::endl;
    } else {
        std::cout << "There is no file!" << std::endl;
    }

    return 0;
}