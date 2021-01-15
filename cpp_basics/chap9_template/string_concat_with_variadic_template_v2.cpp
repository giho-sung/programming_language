#include <iostream>
#include <string>
#include <cstring>

size_t GetStringSize(const char* s) { return strlen(s); }
size_t GetStringSize(const std::string& s) { return s.size(); }
size_t GetStringSize() { return 0; }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
  return GetStringSize(s) + GetStringSize(strs...);
}


void AppendToString(std::string& concat) {
  return ;
}

template <typename String, typename... Strings>
void AppendToString(std::string& concat, String str, Strings... strs) {
  concat.append(str);
  return AppendToString(concat, strs...);
}


template <typename... Strings>
std::string StrCat(const Strings... strs) {
  
  std::string str_concat;
  
  str_concat.reserve(GetStringSize(strs...));

  AppendToString(str_concat, strs...);

  return str_concat;
}


int main() {

	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
	    " ", std::string("sentence"));
}