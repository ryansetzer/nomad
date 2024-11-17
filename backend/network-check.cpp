// Internal
#include "network-check.h"
// External
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <ifaddrs.h>
#include <iostream>
#include <netdb.h>
#include <net/if.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>


void fetchNetInfo() {
  // Creating and filling out Network Interface Struct
  NetInterfaceQuery niq;
  fetchNetInterfacesInfo(niq);

  std::cout << "Main Interface: " << niq.mainIPInterfaceName << std::endl;
  std::cout << "Main IP: " << niq.mainIPAddress << std::endl;

  int unknownInterfaces = 0;
  // Iterating through all found Interfaces
  for (const auto& [key, value] : niq.mappings) {
    switch (key) {
      // IPv4
      case AF_INET:
        std::cout << "IPv4: " << value << std::endl;
        break;
      // IPv6
      case AF_INET6:
        std::cout << "IPv6: " << value << std::endl;
        break;
      // Unknown
      default:
        unknownInterfaces += 1;
        break;
    }
  }
  // Interface(s) not found in Switch Statement
  if (unknownInterfaces > 0) std::cout << "Unknown: " << unknownInterfaces << std::endl;
} 


void fetchNetInterfacesInfo(NetInterfaceQuery & niq) {
  // Address Structs
  struct ifaddrs * interfaces = nullptr;
  struct ifaddrs * ifa = nullptr;

  void * tmpAddrPtr = nullptr;
  std::string primaryIp = "";
  std::string mainInterfaceName = "";

  // Get a list of all network interfaces
  if (getifaddrs(&interfaces) == -1) {
    std::cerr << "Error getting network interfaces" << std::endl;
    return;
  }

  // Iterate through each Interface
  for (ifa = interfaces; ifa != nullptr; ifa = ifa -> ifa_next) {
    // Failed Address
    if (ifa -> ifa_addr == nullptr)
      continue;
    
    // Check if the interface is IPv4
    if (ifa -> ifa_addr -> sa_family == AF_INET) {
      tmpAddrPtr = &((struct sockaddr_in *)ifa -> ifa_addr) -> sin_addr;

      // Convert the IP address to a string
      char addressBuffer[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN) != nullptr) {
        // Assign the primary IP if not already assigned and ensure it's not a loopback interface
        if (primaryIp.empty() && !(ifa -> ifa_flags & IFF_LOOPBACK)) {
          primaryIp = addressBuffer;
          mainInterfaceName = ifa->ifa_name;  // Save the interface name
        }
      }
    }
    // Counting Family Accounts
    niq.mappings[ifa -> ifa_addr -> sa_family] += 1;
  }

  // Clean up
  if (interfaces != nullptr) {
    freeifaddrs(interfaces);
  }

  // Set the main IP and interface name in the query
  niq.mainIPAddress = primaryIp.empty() ? "Unknown" : primaryIp;
  niq.mainIPInterfaceName = mainInterfaceName.empty() ? "Unknown" : mainInterfaceName;
}

bool internetCheck() {
  // Collection of Pingable External
  // Sites to Check Internet Connectivity
  std::string externalSources[] = {
    "google.com",
    "cnn.com",
    "github.com",
    "8.8.8.8",
    "8.8.4.4",
  };

  bool connected = true;
  
  std::string command;
  int result;
  for (const auto & source : externalSources) {
    command = "ping -c 1 " + source + " > /dev/null 2>&1";
    result = system(command.c_str());
    connected = connected || result == 0;
  }

  return connected;
}

