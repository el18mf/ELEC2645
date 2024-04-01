#include "And.h"

//initialising objects
And::And(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2, std::bitset<32> Andoutput) : Binary{input1, input2, bin_input1, bin_input2}, _bin_input1(bin_input1), _bin_input2(bin_input2) {}

void And::set_bin_input1(std::bitset<32> bin_input1) { _bin_input1 = bin_input1; }
void And::set_bin_input2(std::bitset<32> bin_input2) { _bin_input2 = bin_input2; }


std::bitset<32> And::get_Andoutput() {
  _Andoutput =  _bin_input1 & _bin_input2;
  return _Andoutput; // Returns the AND operator output
}

