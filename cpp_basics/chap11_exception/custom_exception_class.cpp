#include <exception>
#include <iostream>

class Parent : public std::exception {
 public:
  // noexcept means no error will occur in the function.
  virtual const char* what() const noexcept override { return "Parent!"; }
};

class Child : public Parent {
 public:
  virtual const char* what() const noexcept override { return "Child!"; }
};

int func(int c) {
  if (c == 1) {
  	throw Parent();
  } else if (c == 2) {
  	throw Child();
  }
  return 0;
}

int main() {
  int c;
  c = 2;

  try {
  	func(c);
  } catch (Parent& p) {
  	std::cout << "Parent catched error!" << std::endl;
  	std::cout << p.what() << std::endl;
  } catch (Child& c) {
  	std::cout << "Child catched error!" << std::endl;
  	std::cout << c.what() << std::endl;
  }
}