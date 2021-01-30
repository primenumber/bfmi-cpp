CXX=g++
CXXFLAGS=-std=c++17 -O3 -flto -march=native -mtune=native -Wall -Wextra

bfmi: bfm_memory.hpp bfm_memory.cpp state.hpp main.cpp
	$(CXX) -o $@ $(CXXFLAGS) bfm_memory.cpp main.cpp

.PHONY: clean
clean:
	-rm bfmi
