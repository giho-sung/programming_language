#include <iostream>
#include <utility>

class A {
 public:
  A() { std::cout << "called normal constructor!" << std::endl; }
  A(const A& a) { std::cout << "called copy constructor!" << std::endl; }
  A(A&& a) { std::cout << "called move constructor!" << std::endl; }
};

int main() {
 A a;
 std::cout << "-------------------------------" << std::endl;
 A b(a);
 std::cout << "-------------------------------" << std::endl;
 // std::move don't move anything. It just transform the value to rvalue.
 A c(std::move(a));
}