#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
 public:
  Vector(size_t size) : size_(size) {
    data_ = new T[size];
    for(int i = 0; i < size_; i++) {
      data_[i] = 3;
    }
  }
  const T& at(size_t index) const{
  	if (index > size_) {
  	  throw std::out_of_range("index of vector exceed range");
  	}
  	return data_[index];
  }
  ~Vector() { delete[] data_; }

 private:
  T* data_;
  size_t size_;
};


int main() {
  Vector<int> vec(3);
  int index, data =0;
  index = 4;

  try {
  	data = vec.at(index);
  } catch (std::out_of_range& e) {
  	std::cout << "exception ocurred! " << e.what() << std::endl;
  }
  
  // if exception not occured, data == 3. if not, data == 0.
  std::cout << "value of data: " << data << std::endl;
}

