#include <iostream>
#include <string>

/*User defined files*/
#include "network-check.h"

const std::string name = "NOMAD";
const std::string YELLOW = "\u001b[33m";
const std::string RESET = "\u001b[0m";


int main() {
  std::cout << "Running: ";
  for (char c : name) {
    std::cout << YELLOW << c << RESET << ".";
  }
  std::cout << "\n";

  int n_check = devices_on_network();
  std::cout << "Devices on network: " << n_check << "\n";

  return 1;
}
