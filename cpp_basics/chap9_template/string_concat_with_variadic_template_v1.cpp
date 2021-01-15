#include <iostream>
#include <string>

template <typename String>
std::string StrCat(String str) {
  return std::string(str);
}

template <typename String, typename... Strings>
std::string StrCat(String str, Strings... strs) {
  return std::string(str) + StrCat(strs...);
}

int main() {
	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
	    " ", std::string("sentence"));
}