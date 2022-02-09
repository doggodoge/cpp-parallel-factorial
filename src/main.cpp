#include <cstdio>
#include <thread>
#include <vector>

void say_hello(std::string const &name);
std::vector<std::thread> init_threads(std::vector<std::string> const &names);
void join_threads(std::vector<std::thread> &threads);

int main() {
  std::vector<std::string> const names{
      "First",
      "Second",
      "Third",
      "Fourth",
      "Fifth",
      "Sixth",
      "Seventh",
      "Eighth",
      "Ninth",
      "Tenth"
  };
  std::vector<std::thread> threads = init_threads(names);
  join_threads(threads);
  return EXIT_SUCCESS;
}

void say_hello(std::string const &name) {
  printf("Hello, %s!\n", name.c_str());
}

std::vector<std::thread> init_threads(std::vector<std::string> const &names) {
  std::vector<std::thread> threads;
  threads.reserve(names.size());
  for (auto name : names) {
    threads.emplace_back(std::thread(say_hello, name));
  }
  return threads;
}

void join_threads(std::vector<std::thread> &threads) {
  for (auto &thread : threads) {
    thread.join();
  }
}
