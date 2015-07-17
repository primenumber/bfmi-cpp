#include <iostream>
#include <string>

#include "state.hpp"

namespace bfm {

bool step(state &st) {
  unsigned char c;
  switch(st.get_prog()) {
   case '+':
    st.inc_val();
    break;
   case '-':
    st.dec_val();
    break;
   case '>':
    st.inc_ptr();
    break;
   case '<':
    st.dec_ptr();
    break;
   case '[':
    st.loop_in();
    break;
   case ']':
    st.loop_out();
    break;
   case '.':
    std::cout << st.get_val();
    break;
   case ',':
    std::cin >> c;
    st.set_val(c);
    break;
   case '\0':
    return false;
  }
  st.inc_prog_ptr();
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
