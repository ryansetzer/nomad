
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <list>
#include <netdb.h>
#include <ostream>

// User Files
#include "arp.h"

std::list<NetworkDevice> arp() {
  // Information from each Device in ARP
  char line[500];
  char ip_address[500];
  int hw_type;
  int flags;
  char mac_address[500];
  char mask[500];
  char device[500];


  std::list<NetworkDevice> networkDevices;



  FILE *fp = fopen("/proc/net/arp", "r");
  fgets(line, sizeof(line), fp);    // Skip the first line (column headers).
  while(fgets(line, sizeof(line), fp))
  {
    // Read the data.
    sscanf(line, "%s 0x%x 0x%x %s %s %s\n",
           ip_address,
           &hw_type,
           &flags,
           mac_address,
           mask,
           device);

    // Declares, Initializes, and Appends Device to all known Devices
    NetworkDevice nd = { ip_address, mac_address, device };
    networkDevices.push_back(nd);
    
    
  }

  fclose(fp);
  return networkDevices;
}
