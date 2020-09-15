# include <iostream>

int change_val(int *p){
    *p = 3;
    return 0;
}

int main(){
    int number = 5;

    // the pointer like C
    std::cout << "pointer as same as in C" << std::endl;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    // the reference which is different with C. C++ only
    std::cout << "reference newly introduced in C++" << std::endl;
    int a = 3;
    int& another_a = a;

    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a " << another_a << std::endl;

    return 0;
}