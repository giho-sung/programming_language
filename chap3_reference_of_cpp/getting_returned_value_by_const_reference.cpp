# include <iostream>

int function(){
    int a = 5;
    return a;
}
int main(){
    // if there is no const at the below def of c, it would post an error during compiling the code.
    const int& c = function();
    std::cout << "c: " << c << std::endl;

    return 0;
}