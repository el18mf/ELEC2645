#ifndef BINARY_H
#define BINARY_H

#include <bitset>
// this class converts the decimal inputs to binary so the operations could be made
class Binary {
 public:
  // only accessors and mutators are public in this example
  Binary();
  Binary(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2);
  void set_input1(int input1);
  void set_input2(int input2);
  std::bitset<32> get_bin_input1();
  std::bitset<32> get_bin_input2();

 private:
  // member variables are private and set/get via accessor/mutator
  int _input1;
  int _input2;
  std::bitset<32> _bin_input1;
  std::bitset<32> _bin_input2;
};
#endif

