#ifndef AND_H
#define AND_H

#include "Binary.h"
#include <bitset>

//this class implements the AND operator
class And : public Binary { // the Binary is used as a subclass here
 public:
  // only accessors and mutators are public in this example
  And();
  And(int input1, int input2, std::bitset<32> bin_input1, std::bitset<32> bin_input2, std::bitset<32> Andoutput);

  void set_input1(int input1);
  void set_input2(int input2);
  void set_bin_input1(std::bitset<32> set_bin_input1);
  void set_bin_input2(std::bitset<32> set_bin_input2);
  std::bitset<32> get_bin_input1;
  std::bitset<32> get_bin_input2;
  std::bitset<32> get_Andoutput();

 private:
  // member variables are private and set/get via accessor/mutator
  int _input1;
  int _input2;
  std::bitset<32> _Andoutput;
  std::bitset<32> _bin_input1;
  std::bitset<32> _bin_input2;
};
#endif

