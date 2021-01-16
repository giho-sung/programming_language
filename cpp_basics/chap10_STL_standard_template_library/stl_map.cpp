#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
  	std::cout << itr->first << " " << itr->second << std::endl;
  }
}

template <typename K, typename V>
void search_and_print(std::map<K, V> m, K key) {
  auto itr = m.find(key);
  if (itr != m.end()) {
  	std::cout << key << " --> " << itr->second << std::endl;
  } else {
  	std::cout << key << "is not on the list" << std::endl;
  }
}

int main() {
  std::map<std::string, double> pitcher_list;
  
  // insert() of map takes std::pair object
  pitcher_list.insert(std::pair<std::string, double>("pack sewoong", 2.23));
  pitcher_list.insert(std::pair<std::string, double>("hacker", 2.93));
  pitcher_list.insert(std::pair<std::string, double>("peer band", 2.95));

  // std::make_pair makes std::pair object guessing types
  pitcher_list.insert(std::make_pair("cha woochan", 3.04));
  pitcher_list.insert(std::make_pair("jang woonjun", 3.05));
  pitcher_list.insert(std::make_pair("hector", 3.09));

  // map could add elements without insert only with []
  pitcher_list["nipert"] = 3.56;
  pitcher_list["pack joonhoon"] = 3.76;
  pitcher_list["kelly"] = 3.90;

  print_map(pitcher_list);
  std::cout << "------------------" << std::endl;
  search_and_print(pitcher_list, std::string("pack sewoong"));
  search_and_print(pitcher_list, std::string("pack chanho"));

}