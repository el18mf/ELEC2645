#include "Not.h"

//initialising objects
Not::Not(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2, std::bitset<32> Notoutput1, std::bitset<32> Notoutput2) : Binary{input1, input2, bin_input1, bin_input2}, _bin_input1(bin_input1), _bin_input2(bin_input2) {}


void Not::set_bin_input1(std::bitset<32> bin_input1) { _bin_input1 = bin_input1; }
void Not::set_bin_input2(std::bitset<32> bin_input2) { _bin_input2 = bin_input2; }

std::bitset<32> Not::get_Notoutput1() {
  _Notoutput1 =  ~_bin_input1;
  return _Notoutput1; // Returns the NOT operator output for the 1st value
}

std::bitset<32> Not::get_Notoutput2() {
  _Notoutput2 = ~ _bin_input2;
  return _Notoutput2; // Returns the NOT operator output for the 2nd value
}
