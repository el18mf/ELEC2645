#include "gates.h"
#include "menu.h"
#include <string>
#include <regex>


//this code has been adapted from the code given in minerva (2.1 code)

void select_chris_menu_item(int input) {
  switch (input) {
    case 1:
      boolean_menu_item_1();
      break;
    case 2:
      boolean_menu_item_2();
      break;
    case 3:
      boolean_menu_item_3();
      break;
    case 4:
      boolean_menu_item_4();
      break;
    case 5:
      boolean_menu_item_5();
      break;
    case 6:
      boolean_menu_item_6();
      break;
    case 7:
      boolean_menu_item_7();
      break;
    case 8:
      boolean_menu_item_8();
      break;        
    default:
      main_menu();
      break;
  }
}


//This code below has been taken from the 2.1 task on minerva and re-worked


bool chris_is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

int get_chris_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 9;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = chris_is_integer(input_string);
    if (valid_input == false) {
      std::cout << "Enter an integer you silly goose!\n";
    } else { 
      input = std::stoi(input_string); 
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item (enter a number between 1 and 9)!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

//this code has been adapted from the code given in minerva (2.1 code)


void logic_gate_calculator_menu() {
  print_logic_gate_calculator_menu();
  int input = get_chris_user_input();
  select_chris_menu_item(input);
}


//Main Menu for my sub-program
void print_logic_gate_calculator_menu() {

  std::cout <<"\n                   ╔▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬╗\n";
  std::cout << "                   ║░░░░░░░░░░░░░░ Logic Gate Menu ░░░░░░░░░░░░░░░░║\n";
  std::cout << "                   ║▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 1 for And gate                  ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 2 for Or gate                   ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 3 for Xor gate                  ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 4 for Nand gate                 ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 5 for XNor gate                 ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 6 for Not gate                  ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 7 for Nor gate                  ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 8 for Buffer gate               ║\n";
  std::cout << "                   ║                                               ║\n";
  std::cout << "                   ║         Press 9 to go back to main menu       ║\n";
  std::cout << "                   ╚═══════════════════════════════════════════════╝\n";


  std::cout << R"(
             zeeeeee-           zeeeeee-            zeeeeee-            zeeeeee-
            z$$$$$$"           z$$$$$$"            z$$$$$$"            z$$$$$$"
           d$$$$$$"           d$$$$$$"            d$$$$$$"            d$$$$$$"
          d$$$$$P            d$$$$$P             d$$$$$P             d$$$$$P 
         d$$$$$P            d$$$$$P             d$$$$$P             d$$$$$P 
        $$$$$$"            $$$$$$"             $$$$$$"             $$$$$$"
      .$$$$$$"           .$$$$$$"            .$$$$$$"             .$$$$$$"
     .$$$$$$"           .$$$$$$"            .$$$$$$"             .$$$$$$"
    4$$$$$$$$$$$$$"    4$$$$$$$$$$$$$"     4$$$$$$$$$$$$$"      4$$$$$$$$$$$$$"
   z$$$$$$$$$$$$$"    z$$$$$$$$$$$$$"     z$$$$$$$$$$$$$"      z$$$$$$$$$$$$$"
   """""""3$$$$$"     """""""3$$$$$"      """""""3$$$$$"      """""""3$$$$$"
         z$$$$P             z$$$$P              z$$$$P              z$$$$P 
        d$$$$"             d$$$$"              d$$$$"              d$$$$"
      .$$$$$"             .$$$$$"             .$$$$$"             .$$$$$"
     z$$$$$"             z$$$$$"             z$$$$$"             z$$$$$"
    z$$$$P              z$$$$P              z$$$$P              z$$$$P
   d$$$$$$$$$$"        d$$$$$$$$$$"        d$$$$$$$$$$"        d$$$$$$$$$$"
  *******$$$"         *******$$$"         *******$$$"         *******$$$"
       .$$$"               .$$$"               .$$$"               .$$$" 
      .$$"                .$$"                .$$"                .$$"
     4$P"                4$P"                4$P"                4$P"
    z$"                 z$"                 z$"                 z$"
   zP                  zP                  zP                  zP
  z"                  z"                  z"                  z"
 /                   /                   /                   /  
^                   ^                   ^                   ^
)" << '\n';


}  



//this code has been adapted from the code given in minerva (2.1 code)

void go_back_to_chris_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'goback' to go back to the Logic Gate menu!: ";
    std::cin >> input;
  }
      while (input != "goback" && input != "Goback" && input != "GOBACK" );

  logic_gate_calculator_menu();
}

void boolean_menu_item_1() {
  std::cout << "AND GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  

  And_Gate (a,b);
  go_back_to_chris_main();
}


void boolean_menu_item_2() {
  std::cout << "OR GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  Or_Gate (a,b);
  go_back_to_chris_main();
}
void boolean_menu_item_3() {
  std::cout << "XOR GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  Xor_Gate (a,b);
  go_back_to_chris_main();
}
void boolean_menu_item_4() {
  std::cout << "NAND GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  Nand_Gate (a,b);
  go_back_to_chris_main();
}
void boolean_menu_item_5() {
  std::cout << "XNOR GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  XNor_Gate (a,b);
  go_back_to_chris_main();
}
void boolean_menu_item_6() {
  std::cout << "NOT GATE CALCULATOR\n ";
  int a;
  std::cout << "Enter binary digit\n ";
  a = get_user_input_boolean();
  Not_Gate (a);
  go_back_to_chris_main();
}
void boolean_menu_item_7() {
  std::cout << "NOR GATE CALCULATOR\n ";
  int a;
  int b;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  std::cout << "Enter binary digit 2\n ";
  b = get_user_input_boolean();
  Nor_Gate (a,b);
  go_back_to_chris_main();
}
void boolean_menu_item_8() {
  std::cout << "Buffer GATE CALCULATOR\n ";
  int a;
  std::cout << "Enter binary digit 1\n ";
  a = get_user_input_boolean();
  Buffer_Gate (a);
  go_back_to_chris_main();
}


//this code below defines the boolean expressions for each logic gate in c++


int Xor_Gate (int a,int b){
  std::cout << "XOR OUTPUT IS\n ";
  int output;
  if (a == b) {
    output = 0;
  }
  else {
    output = 1;
  }
  std::cout << output;
  return output;
}
int And_Gate (int a, int b){
  std::cout << "AND OUTPUT IS\n ";
  int output;
  if (a == 1 && b == 1) {
    output = 1;
  }
  else {
    output = 0;
  }
  std::cout << output;
  return output;
}
int Or_Gate (int a, int b){
  std::cout << "OR OUTPUT IS\n ";
  int output;
  if (a == 1 || b == 1)  {
    output = 1;
  }
  else {
    output = 0;
  }
  std::cout << output;
  return output;
}
int XNor_Gate (int a, int b){
  std::cout << "XNOR OUTPUT IS\n ";
  int output;
  if (a == b) {
    output = 1;
  }
  else {
    output = 0;
  }
  std::cout << output;
  return output;
}
int Nand_Gate (int a, int b){
  std::cout << "NAND OUTPUT IS\n ";
  int output;
  if (a == 1 && b == 1) {
    output = 0;
  }
  else {
    output = 1;
  }
  std::cout << output;
  return output;
}
int Not_Gate (int a){
  std::cout << "NOT OUTPUT IS\n ";
  int output;
  if ( a == 1) {
    output = 0;
  }
  else {
    output = 1;
  }
  std::cout << output;
  return output;
}
int Nor_Gate (int a, int b){
  std::cout << "NOR OUTPUT IS\n ";
  int output;
  if ( a == 0 && b == 0) {
    output = 1;
  }
  else {
    output = 0;
  }
  std::cout << output;
  return output;
}
int Buffer_Gate (int a){
  std::cout << "BUFFER OUTPUT IS\n ";
  int output;
  if ( a == 1) {
    output = 1;
  }
  else {
    output = 0;
  }
  std::cout << output;
  return output;
}



//This code below has been taken from the 2.1 task on minerva and re-worked


int get_user_input_boolean() {
  int a;
  std::string input_string;
  bool valid_input = false;

  do {
    std::cin >> input_string;
    valid_input = chris_is_integer(input_string);
    if (valid_input == false) {
      std::cout << "Enter an integer you silly goose! (either 0 or 1)\n";
    } else { 
      a = std::stoi(input_string); 
      if (a >= 0 && a <= 1) {
        valid_input = true;
      } else {
        std::cout << "Invalid input (enter a number between 0 and 1)!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return a;
}


