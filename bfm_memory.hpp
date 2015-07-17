#pragma once
#include <deque>
#include <string>

namespace bfm {

class memory {
 public:
  memory(const std::string &prog)
    : data(std::begin(prog), std::end(prog)), offset(0) {}
  unsigned char get(int64_t index);
  unsigned char set(int64_t index, unsigned char val);
  unsigned char inc(int64_t index);
  unsigned char dec(int64_t index);
  int64_t find_match(int64_t index) const;
 private:
  std::deque<unsigned char> data;
  int64_t offset;
  int64_t find_match_forward(int64_t index) const;
  int64_t find_match_backward(int64_t index) const;
  int64_t index_to_trueindex(int64_t index) const;
  int64_t trueindex_to_index(int64_t true_index) const;
  unsigned char &operator[](int64_t index);
};

} // namespace bfm
