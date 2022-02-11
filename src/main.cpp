#include <iostream>
#include <string>
#include "parallel_factorial.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << "Please enter a number.";
    return EXIT_FAILURE;
  }
  auto const limit = std::strtol(argv[1], nullptr, 10);
  std::string result = parallel_factorial(limit);
  std::cout << result << std::endl;
  return EXIT_SUCCESS;
}
