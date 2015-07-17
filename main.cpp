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
  switch(st.mem[st.prog_index]) {
   case '+':
    ++st.mem[st.data_index];
    break;
   case '-':
    --st.mem[st.data_index];
    break;
   case '>':
    ++st.data_index;
    break;
   case '<':
    --st.data_index;
    break;
   case '[':
    if (st.mem[st.data_index] == 0) {
      st.prog_index = st.mem.find_match(st.prog_index);
    }
    break;
   case ']':
    if (st.mem[st.data_index] != 0) {
      st.prog_index = st.mem.find_match(st.prog_index);
    }
    break;
   case '.':
    std::cout << st.mem[st.data_index];
    break;
   case ',':
    std::cin >> st.mem[st.data_index];
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
