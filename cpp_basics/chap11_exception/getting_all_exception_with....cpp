#include <iostream>
#include <stdexcept>

int func (int c) {
  if (c == 1) {
    throw 1;
  } else if (c == 2) {
  	throw "hi";
  } else if (c == 3) {
  	throw std::runtime_error("error");
  }
  return 0;
}

int main() {
  int c;
  c = 3;

  try {
  	func(c);
  } catch (int e) {
  	std::cout << "Catch int : " << e << std::endl;
  // getting all exception using '...''
  // this sort of catch used to use in template
  } catch (...) {
     std::cout << "default catch!" << std::endl; 
  }
}