#include <iostream>
#include <string>

#include "bfm_memory.hpp"

namespace bfm {

struct state {
  memory mem;
  int64_t prog_index;
  int64_t data_index;
  state(const std::string &prog)
    : mem(prog), prog_index(0), data_index(0) {}
};

bool step(state &st) {
  unsigned char c;
  switch(st.mem.get(st.prog_index)) {
   case '+':
    st.mem.inc(st.data_index);
    break;
   case '-':
    st.mem.dec(st.data_index);
    break;
   case '>':
    ++st.data_index;
    break;
   case '<':
    --st.data_index;
    break;
   case '[':
    if (st.mem.get(st.data_index) == 0) {
      st.prog_index = st.mem.find_match(st.prog_index);
    }
    break;
   case ']':
    if (st.mem.get(st.data_index) != 0) {
      st.prog_index = st.mem.find_match(st.prog_index);
    }
    break;
   case '.':
    std::cout << st.mem.get(st.data_index);
    break;
   case ',':
    std::cin >> c;
    st.mem.set(st.data_index, c);
    break;
   case '\0':
    return false;
  }
  ++st.prog_index;
  return true;
}

void run_bfm(const std::string &prog) {
  state st(prog);
  while(step(st));
}

} // namespace bfm

int main() {
  std::string prog;
  std::string line;
  while(std::getline(std::cin, line)) {
    prog += line + '\n';
  }
  bfm::run_bfm(prog);
  return 0;
}
