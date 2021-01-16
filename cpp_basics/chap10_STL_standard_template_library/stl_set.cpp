#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) {
  // print all elements in a set
  std::cout << "[ ";
  for(typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
  	std::cout << *itr << " ";
  }
  std::cout << " ] " << std::endl;
}

int main() {
  std::set<int> s;
  s.insert(10);
  s.insert(50);
  s.insert(20);
  s.insert(40);
  s.insert(30);
  s.insert(10);

  std::cout << "elements are already ordered in the set s" << std::endl;
  print_set(s);
  
  std::cout << "Is 20 a element of the set s? ";
  auto itr = s.find(20);
  if (itr != s.end()) {
  	std::cout << "Yes" << std::endl;
  } else {
  	std::cout << "No" << std::endl;
  }

  std::cout << "Is 25 a element of the set s? ";
  itr = s.find(25);
  if(itr != s.end()) {
  	std::cout << "Yes" << std::endl;
  } else {
  	std::cout << "No" << std::endl;
  }
}