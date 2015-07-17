#pragma once
#include "bfm_memory.hpp"

namespace bfm {

struct state {
  state(const std::string &prog)
    : mem(prog), prog_index(0), data_index(0) {}
  unsigned char get_prog() { return mem.get(prog_index); }
  void inc_val() { mem.inc(data_index); }
  void dec_val() { mem.dec(data_index); }
  void inc_ptr() { ++data_index; }
  void dec_ptr() { --data_index; }
  void loop_in() {
    if (mem.get(data_index) == 0) {
      prog_index = find_match();
    }
  }
  void loop_out() {
    if (mem.get(data_index) != 0) {
      prog_index = find_match();
    }
  }
  unsigned char get_val() { return mem.get(data_index); }
  void set_val(unsigned char c) { mem.set(data_index, c); }
  void inc_prog_ptr() { ++prog_index; }
 private:
  memory mem;
  int64_t prog_index;
  int64_t data_index;
  int64_t find_match() {
    return mem.find_match(prog_index);
  }
};

} // namespace bfm
