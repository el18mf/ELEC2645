#include "Xor.h"

//initialising objects
Xor::Xor(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2, std::bitset<32> Xoroutput) : Binary{input1, input2, bin_input1, bin_input2}, _bin_input1(bin_input1), _bin_input2(bin_input2) {}


void Xor::set_bin_input1(std::bitset<32> bin_input1) { _bin_input1 = bin_input1; }
void Xor::set_bin_input2(std::bitset<32> bin_input2) { _bin_input2 = bin_input2; }

std::bitset<32> Xor::get_Xoroutput() {
  _Xoroutput =  _bin_input1 ^ _bin_input2;
  return _Xoroutput; // Returns the XOR operator output
}

