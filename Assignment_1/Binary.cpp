#include "Binary.h"

Binary::Binary(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2) : _input1{input1}, _input2{input2} {}

// mutator method to set radius
void Binary::set_input1(int input1) { _input1 = input1; }
void Binary::set_input2(int input2) { _input2 = input2; }


std::bitset<32> Binary::get_bin_input1() {
  std::bitset<32> byte_one(_input1);
  _bin_input1 = byte_one;
  return _bin_input1;
}

std::bitset<32> Binary::get_bin_input2() {
  std::bitset<32> byte_two(_input2);
  _bin_input2 = byte_two;
  return _bin_input2;
}