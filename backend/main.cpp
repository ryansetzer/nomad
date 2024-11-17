#include <iostream>
#include <sys/socket.h>

/*User defined files*/
#include "arp.h"
#include "cli-ops.h"
#include "main.h"
#include "network-check.h"

int main() {
  display_welcome();
  fetchNetInfo();
  std::list<NetworkDevice> devices = arp();
  for (NetworkDevice nd : devices) {
    std::cout <<
      "Test: " << 
      nd.IPv4 << "\t" <<
      nd.MAC << "\t" <<
      nd.interface <<
      std::endl;
  }
  return 1;
}
