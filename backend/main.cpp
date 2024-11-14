#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unordered_map>

/*User defined files*/
#include "main.h"
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

  std::unordered_map<std::string, int> interfacesSum;
  NetInterfaceQuery niq;
  fetchNetInterfacesInfo(niq);

  std::cout << "Main Interface: " << niq.mainIPInterfaceName << std::endl;
  std::cout << "Main IP: " << niq.mainIPAddress << std::endl;

  int unknownInterfaces = 0;
  for (const auto& [key, value] : niq.mappings) {
    switch (key) {
      case AF_INET:
        std::cout << "IPv4: " << value << std::endl;
        break;
      case AF_INET6:
        std::cout << "IPv6: " << value << std::endl;
        break;
      default:
        unknownInterfaces += 1;
        break;
    }
  }
  if (unknownInterfaces > 0) std::cout << "Unknown: " << unknownInterfaces << std::endl;
  return 1;
}
