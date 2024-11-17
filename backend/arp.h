#include <list>
#include <string>


struct NetworkDevice {
  std::string IPv4;
  std::string MAC;
  std::string interface;
};

std::list<NetworkDevice> arp();
