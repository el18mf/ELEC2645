#include "Or.h"

//initialising objects
Or::Or(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2, std::bitset<32> Oroutput) : Binary{input1, input2, bin_input1, bin_input2}, _bin_input1(bin_input1), _bin_input2(bin_input2) {}


void Or::set_bin_input1(std::bitset<32> bin_input1) { _bin_input1 = bin_input1; }
void Or::set_bin_input2(std::bitset<32> bin_input2) { _bin_input2 = bin_input2; }

std::bitset<32> Or::get_Oroutput() {
  _Oroutput =  _bin_input1 | _bin_input2;
  return _Oroutput; // Returns the OR operator output
}

