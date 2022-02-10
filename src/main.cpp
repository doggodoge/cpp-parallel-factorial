#include <cstdio>
#include <string>
#include "parallel_factorial.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::fprintf(stderr, "Please enter a valid number.\n");
    return EXIT_FAILURE;
  }
  auto limit = std::strtol(argv[1], nullptr, 10);
  std::string result = parallel_factorial(limit);
  std::printf("%s\n", result.c_str());
  return EXIT_SUCCESS;
}
