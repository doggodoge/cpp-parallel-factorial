#include <future>
#include <gmp.h>
#include <vector>

auto const processor_count = std::thread::hardware_concurrency();

struct FactorialRange {
  long start, end;
  FactorialRange(long start, long end) {
    this->start = start;
    this->end = end;
  }
};

std::vector<FactorialRange> get_ranges(long limit);
std::string factorial_chunk(long start, long end);
std::string
arbitrary_precision_product(std::vector<std::string> const &str_numbers);
std::vector<std::future<std::string>>
init_futures(std::vector<FactorialRange> const &ranges);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::fprintf(stderr, "Please enter a valid number.\n");
    return EXIT_FAILURE;
  }

  auto limit = std::strtol(argv[1], nullptr, 10);
  std::vector<FactorialRange> ranges = get_ranges(limit);

  auto futures = init_futures(ranges);
  std::vector<std::string> results;
  results.reserve(processor_count);
  for (auto &future : futures) {
    results.emplace_back(future.get());
  }
  std::string const result = arbitrary_precision_product(results);
  std::printf("%s\n", result.c_str());
  return EXIT_SUCCESS;
}

std::vector<FactorialRange> get_ranges(long limit) {
  if (limit < processor_count) {
    return std::vector{FactorialRange(1, limit)};
  }
  std::vector<FactorialRange> ranges;
  ranges.reserve(processor_count);
  long const chunk_size = limit / processor_count + 1;
  long start = 1;
  for (auto i = 0; i < processor_count; i++) {
    if (start + chunk_size > limit) {
      ranges.emplace_back(FactorialRange(start, limit));
    } else {
      ranges.emplace_back(FactorialRange(start, start + chunk_size));
    }
    start += chunk_size + 1;
  }
  return ranges;
}

std::string factorial_chunk(long start, long end) {
  mpz_t acc;
  mpz_init_set_ui(acc, 1);
  for (long i = start; i <= end; i++) {
    mpz_mul_ui(acc, acc, i);
  }
  auto result = std::string(mpz_get_str(nullptr, 10, acc));
  mpz_clear(acc);
  return result;
}

std::string
arbitrary_precision_product(std::vector<std::string> const &str_numbers) {
  mpz_t acc, operand;
  mpz_init_set_ui(acc, 1);
  mpz_init_set_ui(operand, 1);
  for (auto const &number_str : str_numbers) {
    mpz_set_str(operand, number_str.c_str(), 10);
    mpz_mul(acc, acc, operand);
  }
  auto result = std::string(mpz_get_str(nullptr, 10, acc));
  mpz_clear(acc);
  mpz_clear(operand);
  return result;
}

std::vector<std::future<std::string>>
init_futures(std::vector<FactorialRange> const &ranges) {
  std::vector<std::future<std::string>> futures;
  futures.reserve(ranges.size());
  for (auto range : ranges) {
    futures.emplace_back(std::async(factorial_chunk, range.start, range.end));
  }
  return futures;
}
