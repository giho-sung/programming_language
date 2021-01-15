#include <iostream>

int sum_all(){
  return 0;
}

template <typename... Ints>
int sum_all(int num, Ints... ints) {
  return num + sum_all(ints...);
}

template <typename... Ints>
double average(Ints... ints) {
  return static_cast<double>(sum_all(ints...)) / sizeof...(ints);
}

int main() {
  std::cout << average(1, 4, 2, 3, 10) << std::endl;
}