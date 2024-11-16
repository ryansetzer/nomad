#ifndef NETWORK_CHECK_H
#define NETWORK_CHECK_H

#include <string>
#include <unordered_map>

struct NetInterfaceQuery {
  std::string mainIPInterfaceName;
  std::string mainIPAddress;
  std::unordered_map<int, int> mappings;
};

void fetchNetInfo();
void fetchNetInterfacesInfo(NetInterfaceQuery &);
std::string getPrimaryIpAddress();

#endif
