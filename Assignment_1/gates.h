#include <regex>
#include <iostream>
#include <string>

// "XOR" gate functio.n true if and only if its arguments differ
int Xor_Gate (int a, int b);
//"AND" gate function. Gives the value one if and only if all the operands are one, and otherwise has a value of zero
int And_Gate (int a, int b);
//"OR" gate function. Gives the value one if at least one operand has the value one, and otherwise gives a value of zero
int Or_Gate (int a, int b);
//"XNOR" gate function. Outputs 1 if both of the inputs to the gate are the same. otherwise outputs 0
int XNor_Gate (int a, int b);
//"NOT" gate function. Outputs the opposite of its input
int Not_Gate (int a);
//"NAND" gate function. Gives the value zero if and only if all the operands have a value of one, and otherwise has a value of one
int Nand_Gate (int a, int b);
//"NOR" gate function. Gives the value one if and only if all operands have a value of zero and otherwise has a value of zero
int Nor_Gate (int a, int b);
//"BUFFER" gate function. Gives the same value that is inputted 
int Buffer_Gate (int a);


//this makes sure the user can only input a "0" or a "1"
int get_user_input_boolean();


//Main Menu for my sub-program
void logic_gate_calculator_menu();

//used to get the value assossiated with the users selection
int get__chris_user_input();

//used in conjuction with the users input integer to determine and then call the appropriate function
void select_chris_menu_item(int input);

//used to print the GUI of the selection menu for the op-amp calculator sub-program
void print_logic_gate_calculator_menu();

//used to go back to the calculator selection screen in case you entered the wrong value
//void go_back_to_main_menu();

//used to check whether the user input to select which logic gate calculator function is a valid selection (one of the numbers corresponding to a function). If it is not one of those numbers the program will tell the user and stop
bool chris_is_integer(std::string num);


//First menu option, takes you to the "AND" gate function
void boolean_menu_item_1();
//Second menu option, takes you to the "OR" gate function
void boolean_menu_item_2();
//Third menu option, takes you to the "XOR" gate function
void boolean_menu_item_3();
//Fourth menu option, takes you to the "NAND" gate function
void boolean_menu_item_4();
//Fifth menu option, takes you to the "XNOR" gate function
void boolean_menu_item_5();
//Sixth menu option, takes you to the "NOT" gate function
void boolean_menu_item_6();
//Seventh menu option, takes you to the "NOR" gate function
void boolean_menu_item_7();
//Eighth menu option, takes you to the "BUFFER" gate function
void boolean_menu_item_8();
//Nineth menu option, takes you to the main menu of the program
