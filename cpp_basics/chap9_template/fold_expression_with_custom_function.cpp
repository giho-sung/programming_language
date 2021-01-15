#include <iostream>

class A {
 public:

  template <typename T>
  void do_something(T x) const {
    std::cout << "Do something with " << x << std::endl;
  }
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
  // calling do_sumthing all the argument in nums
  (t.do_something(nums), ...);
}

int main() {
  A a;
  do_many_things(a, 1, 3, 2, 4);
}