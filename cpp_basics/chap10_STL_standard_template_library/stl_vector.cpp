#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
    std::cout << *itr << std::endl;
  }

  for (const auto& elem : vec) {
  	std::cout << elem << std::endl;
  }

  std::vector<int>::iterator itr = vec.begin() + 2;
  std::cout << "3rd element : " << *itr << std::endl; 
}