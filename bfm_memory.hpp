#pragma once
#include <deque>
#include <string>

namespace bfm {

class memory {
 public:
  memory(const std::string &prog)
    : data(std::begin(prog), std::end(prog)), offset(0) {}
  unsigned char &operator[](int64_t index);
  int64_t find_match(int64_t index);
 private:
  std::deque<unsigned char> data;
  int64_t offset;
  int64_t find_match_forward(int64_t index);
  int64_t find_match_backward(int64_t index);
  int64_t index_to_trueindex(int64_t index);
  int64_t trueindex_to_index(int64_t true_index);
};

} // namespace bfm
