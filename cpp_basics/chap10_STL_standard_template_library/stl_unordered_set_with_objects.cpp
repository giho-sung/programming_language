#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(std::unordered_set<K>& m) {
  for (const auto& elem : m) {
  	std::cout << elem << std::endl;
  }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
  auto itr = s.find(key);
  if (itr != s.end()) {
  	std::cout << key << "exist" << std::endl;
  } else {
  	std::cout << key << "not exist" << std::endl;
  }
}

class Todo {
  int priority;
  std::string job_desc;

 public:
  Todo(int priority, std::string job_desc)
      : priority(priority), job_desc(job_desc) {}


  // unordered_set use hash. overwriting opertor== is needed to compare the value is smae or not
  // within hash table.
  bool operator==(const Todo& t) const {
  	if(priority == t.priority & job_desc == t.job_desc) return true;
  	return false;
  }

  friend std::ostream& operator<<(std::ostream& o, const Todo& t);
  friend struct std::hash<Todo>;
};

// We explicitly write namespace of function to overload hash function which is in namespace 'std'
namespace std {
template<>
struct hash<Todo> {
  size_t operator()(const Todo& t) const {
  	hash<string> hash_func;
    return t.priority ^ (hash_func(t.job_desc));
  }
};
}// end namespace std

std::ostream& operator<<(std::ostream& o, const Todo& t) {
  return o << "[priority: " << t.priority << "] " << t.job_desc;
}


int main() {
  std::unordered_set<Todo> todos;

  todos.insert(Todo(1, "Playing basketball"));
  todos.insert(Todo(2, "Doing math homework"));
  todos.insert(Todo(1, "Doing programming project"));
  todos.insert(Todo(3, "Meeting freiends"));
  todos.insert(Todo(2, "Watching movie"));

  print_unordered_set(todos);
  std::cout << "------------------------" << std::endl;
}
