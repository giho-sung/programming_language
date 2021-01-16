#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
  for (const auto& elem : s) {
  	std::cout << elem << " " << std::endl;
  }
}

class Todo {
  int priority;
  std::string job_desc;

 public:
  Todo(int priority, std::string job_desc)
      : priority(priority), job_desc(job_desc) {}
  
  // two const is eccential to order in set. 
  bool operator<(const Todo& t) const {
  	if(priority == t.priority) {
  	  return job_desc < t.job_desc;
  	}
  	return priority > t.priority;
  }

  friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
  o << "[Priority: " << td.priority << "] " << td.job_desc;
  return o;
}

int main() {
  std::set<Todo> todos;
  todos.insert(Todo(1, "Playing basketball"));
  todos.insert(Todo(2, "Doing math homework"));
  todos.insert(Todo(1, "Doing programming project"));
  todos.insert(Todo(3, "Meeting friends"));
  todos.insert(Todo(2, "Watching movie"));

  print_set(todos);

  std::cout << "--------------------" << std::endl;
  std::cout << "if you finished doing homework!" << std::endl;
  todos.erase(todos.find(Todo(2, "Doing math homework")));
  print_set(todos);
}