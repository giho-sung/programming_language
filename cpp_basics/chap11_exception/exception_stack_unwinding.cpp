#include <iostream>
#include <stdexcept>

class Resource {
  public:
   Resource(int id) : id_(id) {}
   ~Resource() { std::cout << "Release resource: " << id_ << std::endl; }
  private:
   int id_;
};


int func3() {
  Resource r(3);
  throw std::runtime_error("Exception from func3!");
}

int func2() {
  Resource r(2);
  func3();
  std::cout << "not run!" << std::endl;
  return 0;
}

int func1() {
  Resource r(1);
  func2();
  std::cout << "not run!" << std::endl;
  return 0;
}

int main() {
  try {
  	func1();
  } catch (std::exception& e) {
  	std::cout << "Exception: " << e.what() << std::endl;
  }
}