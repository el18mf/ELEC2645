#include <iostream>
#include <regex>
#include "Boolean_Operators.h"
#include "Binary.h"
#include "And.h"
#include "Xor.h"
#include "Not.h"
#include "Or.h"
#include "menu.h"

// I don't know if a reference is needed or not as I am using the same coding style as the example given for us from DR. Timothy Amsdon

//intialising
int input1;
int input2;
std::bitset<32> binary_input1;
std::bitset<32> binary_input2;
std::bitset<32> AND_output;
std::bitset<32> XOR_output;
std::bitset<32> NOT_output1;
std::bitset<32> NOT_output2;
std::bitset<32> OR_output;

// that's my main void functions that shows my menu option.
void boolean_operators_menu() {
  print_boolean_operators_menu();
  int input = get_user_input();
  select_menu_item(input);
}
//Checking if each char in a string is a decimal digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}
// a void function to get the user to choose from 1-5 only and if he typed any other value that that it will just show an invalid input message and asks him to reselect the item.
int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

// this one contains the code for each menu item in my menu option, and the codes are simply done separately and just called them here.
void select_menu_item(int input) {
  switch (input) {
      case 1:
      AND();
      break;
      case 2:
      XOR();
      break;
      case 3:
      NOT();
      break;
      case 4:
      OR();
      break;
    default:
      main_menu();
      break;
  }
}

// The GUI of my menu option 
void print_boolean_operators_menu() {
  // I'm using the same GUI as my teammate Mathew Fuller to make our Calculator look better (he's the one who came up with it)
  std::cout << "\n╔▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬╗\n";
  std::cout << "║░░░░░░░░░░░░░░ Boolen Operators ░░░░░░░░░░░░░░░║\n";
  std::cout << "║▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║           1. &Bit-wise AND&                   ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║           2. ^Bit-wise XOR^                   ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║           3. ~Bit-wise NOT~                   ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║           4. |Bit-wise OR|                    ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║      <==  5. Return to Main menu              ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "╚═══════════════════════════════════════════════╝\n";
}

// it's a function that makes the user reselect a menu item and re-enter new values.
void go_back_to_menu() {
  std::string input;
  std::cout << "\nEnter 'r'/'R' to re-use this menu option: ";
  do {
    std::cin >> input;
  } while (input != "r" && input != "R");
  boolean_operators_menu();
}

//transferring inputs from decimals to binary.
void Binary(){
  //making the user enter 2 inputs.
  std::cout << "Enter your 1st value (in decimals): ";
  std::cin >> input1;
  std::cout << "Enter your 2nd value (in decimals): ";
  std::cin >> input2;

  // calling the class
  class Binary binary(input1, input2, binary_input1, binary_input2);
  binary_input1 = binary.get_bin_input1();
  std::cout << "The 1st value in binary is: " << "\n"<< binary_input1 << "\n";
  binary_input2 = binary.get_bin_input2();
  std::cout << "The 2nd value in binary is: " << "\n"<< binary_input2 << "\n";
}

void AND() {
  std::cout << "\n>> Bit-wise AND\n";
  Binary();

  And And(input1, input2, binary_input1, binary_input2, AND_output);
  AND_output = And.get_Andoutput();
  std::cout << "The result of the AND operation in binary is: " << "\n"<< AND_output << "\n";
  // this a code to print the output in decimals too.
  std::cout << "The result of the AND operation in decimals is: " <<  AND_output.to_ulong() << "\n";
  go_back_to_menu();
}
void XOR() {
  std::cout << "\n>> Bit-wise XOR\n";
  Binary();

  Xor Xor(input1, input2, binary_input1, binary_input2, XOR_output);
  XOR_output = Xor.get_Xoroutput();
  std::cout << "The result of the XOR operation in binary is: " << "\n"<< XOR_output << "\n";
  // this a code to print the output in decimals too.
  std::cout << "The result of the AND operation in decimals is: " <<  XOR_output.to_ulong() << "\n";
  go_back_to_menu();
}
void NOT() {
  std::cout << "\n>> Bit-wise NOT\n";
  Binary();

  Not Not(input1, input2, binary_input1, binary_input2, NOT_output1, NOT_output2);
  NOT_output1 = Not.get_Notoutput1();
  std::cout << "The 1st value output of the NOT operation in binary is: " << "\n"<< NOT_output1 << "\n";
  // this a code to print the output in decimals too.
  std::cout << "The result of the AND operation in decimals is: " <<  NOT_output1.to_ulong() << "\n";
  
  NOT_output2 = Not.get_Notoutput2();
  std::cout << "The 2nd value output of the NOT operation in binary is: " << "\n"<< NOT_output2 << "\n";
  // this a code to print the output in decimals too.
  std::cout << "The result of the AND operation in decimals is: " <<  NOT_output2.to_ulong() << "\n";
  go_back_to_menu();
}
void OR() {
  std::cout << "\n>> Bit-wise OR\n";
  Binary();
  
  Or Or(input1, input2, binary_input1, binary_input2, OR_output);
  OR_output = Or.get_Oroutput();
  std::cout << "The result of the OR operation in binary is: " << "\n"<< OR_output << "\n";
  // this a code to print the output in decimals too.
  std::cout << "The result of the AND operation in decimals is: " <<  OR_output.to_ulong() << "\n";
  go_back_to_menu();
}