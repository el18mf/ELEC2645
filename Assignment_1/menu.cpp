#include <iostream>
#include <string>
#include <regex>
#include "menu.h"
#include "opamp.h"
#include "gates.h"
#include "Boolean_Operators.h"

void main_menu() {
  print_main_menu();
  int input = get_main_user_input();
  main_menu_select(input);
}

int get_main_user_input() {
    int input;
    std::string string_selection;
    bool inputvalid = false;
    int main_menu_amount = 4;

    do {
      std::cout << "\n Select Calculator to use: ";
        std::cin >> string_selection;
      inputvalid = main_is_integer(string_selection);

    if (inputvalid == false) {
      std::cout << "Invalid Selection! Input selection 1 to 4.\n";
    } else { 
      input = std::stoi(string_selection);
        if (input >= 1 && input <= main_menu_amount) {
          inputvalid = true;
        } else {
            std::cout << "Invalid Selection! Input selection 1 to 4.\n";
            inputvalid = false;
        }
 
    }
  } while (inputvalid == false);
  return input;
}

void main_menu_select(int input) {
  switch (input) {
    //Case 1 is used to initialise the sub-program created by Mathew F, which is a calculator that contains the ability to find the output of several Operational-Amplifier (Op-amp) related gain equations, the ability to find the Feedback Ratio of an Op-amp and the ability to convert Gain to Decibel's
    case 1:
      opamp_menu();
      break;
    case 2:
      boolean_operators_menu();
      break;
    case 3:
      logic_gate_calculator_menu();
      break;
    default:
      std::cout << "\n███████████████████████████████████████████████████████████████████████████████████";
      std::cout << "\n███████▀███████████████████████████████████████████████████████████████████████████";
      std::cout << "\n██████░░███████████████████████████████▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀███████████████████████▀▀███";
      std::cout << "\n█████▀░▄███████████████████████████████▄▄▄▄▄▄▄░░▄▄▄▄▄▄▄█▀▀████████████████████░░███";
      std::cout << "\n█████░░▀▀▀▀▀███▀▀█████▀▀███▀▀▀▀▀██████████████░░████████▄▄████████████████████░░███";
      std::cout << "\n█████░░▄██▄░░███░░███░░███░░███░░█████████████░░██████████████████████████████░░███";
      std::cout << "\n████░░█████░░███░▄███░░██░░▀▀▀░▄██████████████░░████████▀▀████████████████████░░███";
      std::cout << "\n████░░████▀░███░░███▀░███░░███████████████████░░████████░░████░░▀▀▀▀██▀▀▀▀████░░███";
      std::cout << "\n████░░█▀▀░▄████▄░▀▀▀░▄███▄░▀▀▀░▄██████████████░░████████░░████░░▄██▄░░▄██▄░▀██▄▄███";
      std::cout << "\n█████▄▄▄███████████░░██████▄▄█████████████████░░████████░░████░░████░░████░░██▀▀███";
      std::cout << "\n██████████████░▀█▀░▄██████████████████████████▄▄████████▄▄████▄▄████▄▄████▄▄██▄▄███";
      std::cout << "\n███████████████▄▄▄█████████████████████████████████████████████████████████████████";
      std::cout << "\n███████████████████████████████████████████████████████████████████████████████████";

      /* Added original ascii bye to be used if the program is used outside of the elec2645 project so that the end message is not specific to our module leader Tim. All credit for the original ascii is to an anonymous user who posted it here: https://textart4u.blogspot.com/2012/05/good-bye-written-in-ascii-text-art.html
        std::cout << "\n████████████████████████████████████";
        std::cout << "\n███████▀████████████████████████████";
        std::cout << "\n██████░░████████████████████████████";
        std::cout << "\n█████▀░▄████████████████████████████";
        std::cout << "\n█████░░▀▀▀▀▀███▀▀█████▀▀███▀▀▀▀▀████";
        std::cout << "\n█████░░▄██▄░░███░░███░░███░░███░░███";
        std::cout << "\n████░░█████░░███░▄███░░██░░▀▀▀░▄████";
        std::cout << "\n████░░████▀░███░░███▀░███░░█████████";
        std::cout << "\n████░░█▀▀░▄████▄░▀▀▀░▄███▄░▀▀▀░▄████";
        std::cout << "\n█████▄▄▄███████████░░██████▄▄███████";
        std::cout << "\n██████████████░▀█▀░▄████████████████";
        std::cout << "\n███████████████▄▄▄██████████████████";
        std::cout << "\n████████████████████████████████████"; */
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n╔▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬╗\n";
  std::cout << "║░░░░░░░░░░░░░░░░░░ Main Menu ░░░░░░░░░░░░░░░░░░║\n";
  std::cout << "║▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         1. Op-Amp Gain Calculator             ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         2. Boolean Operators Calculator       ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         3. Logic Gate Calculator              ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         4. Exit                               ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "╚═══════════════════════════════════════════════╝\n";
}

bool main_is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}



