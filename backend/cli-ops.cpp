#include <iostream>
#include <string>

#include "cli-ops.h"

void display_welcome() {
  std::cout << "Running: ";
  for (char c : name) {
    std::cout << YELLOW << c << RESET << ".";
  }
  std::cout << "\n";


}
