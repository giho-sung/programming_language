#include <iostream>
#include <vector>

template <typename T>
void sort_list(std::vector<T>& data) {
  for (size_t i = 1; i < data.size(); i++) {
      for (size_t j = 0; j < data.size() -i; j++) {
          if(data[j] > data[j + 1]) {
              //changing data[j] and data[j + 1]
              T temp = std::move(data[j]);
              data[j] = std::move(data[j + 1]);
              data[j + 1] = std::move(temp);
          }
      }
  }
}

int main() {
  std::vector<int> s = {1, 9, 8, 5, 4, 6, 7, 3, 2, 10};
  sort_list(s);

  for (int num : s) {
    std::cout << num << " ";
  }
}