# include <iostream>

int main(){
    
    // creating an variable in heap space
    int* p = new int;
    *p = 10;

    std::cout << *p << std::endl;

    delete p;

    // trying to delete an variable which not belongs to heap space.
    int a = 5;
    delete &a;

    return 0;
}