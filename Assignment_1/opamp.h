#include <iostream>
#include <string>

//First equation to find A (open loop gain) using the voltages in the equation Vout = A(V+-V-) by re-arranging it to A= Vout/(V+ - V-)
void gainequation1();

//Second Equation option, to find the closed loop gain. i.e. for non-inverting G = 1+R2/R1 where G = Closed-loop gain, A = Open-loop gain, R1 & R2 are the resistors
void gainequation2();

//third equation option, to find the open, closed or total loop gain. i.e. for non-inverting G = A/(1+AB) where G = Closed-loop gain, A = Open-loop gain, AB = Loop Gain
void gainequation3();

//Gain Bandwidth Product (GBP), which is used to find A under Ft (frequency when A=1)
void gainequation4();

//Gain to decibel conversion equation 
void gainequation5();

//Equation to find Feedback ratio (B)
void gainequation6();

//Main Menu for my sub-program
void opamp_menu();

//used to get the value assossiated with the users selection
int opamp_get_user_input();

//used in conjuction with the users input integer to determine and then call the appropriate function
void menu_select(int input);

//used to print the GUI of the selection menu for the op-amp calculator sub-program
void print_opamp_menu();

//used to go back to the calculator selection screen in case you entered the wrong value
void go_back_to_opamp_menu();

//used to check whether the user input to select which calculator function is a valid selection (one of the numbers corresponding to a function)
bool opamp_is_integer(std::string num);