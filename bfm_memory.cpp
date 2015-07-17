#include "bfm_memory.hpp"

namespace bfm {

int64_t memory::index_to_trueindex(int64_t index) const {
  return index + offset;
}

int64_t memory::trueindex_to_index(int64_t true_index) const {
  return true_index - offset;
}

unsigned char &memory::operator[](int64_t index) {
  int64_t true_index = index_to_trueindex(index);
  while (true_index < 0) {
    data.push_front(0);
    ++offset;
    ++true_index;
  }
  while (true_index >= data.size()) {
    data.push_back(0);
  }
  return data[true_index];
}

unsigned char memory::get(int64_t index) {
  return (*this)[index];
}

unsigned char memory::set(int64_t index, unsigned char val) {
  return (*this)[index] = val;
}

unsigned char memory::inc(int64_t index) {
  return ++(*this)[index];
}

unsigned char memory::dec(int64_t index) {
  return --(*this)[index];
}

int64_t memory::find_match_forward(int64_t index) const {
  int64_t true_index = index_to_trueindex(index);
  int64_t count = 1;
  while (count > 0 && ++true_index < data.size()) {
    switch (data[true_index]) {
     case '[':
      ++count; break;
     case ']':
      --count; break;
    }
  }
  if (true_index == data.size()) throw "unmatched bracket";
  return trueindex_to_index(true_index);
}

int64_t memory::find_match_backward(int64_t index) const {
  int64_t true_index = index_to_trueindex(index);
  int64_t count = 1;
  while (count > 0 && --true_index >= 0) {
    switch (data[true_index]) {
     case '[':
      --count; break;
     case ']':
      ++count; break;
    }
  }
  if (true_index == -1) throw "unmatched bracket";
  return trueindex_to_index(true_index);
}

int64_t memory::find_match(int64_t index) const {
  int64_t true_index = index_to_trueindex(index);
  switch (data[true_index]) {
   case '[':
    return find_match_forward(index);
   case ']':
    return find_match_backward(index);
   default:
    throw "it is not bracket";
  }
}

} // namespace bfm
