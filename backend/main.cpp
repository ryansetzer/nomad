#include <iostream>
#include <sys/socket.h>

/*User defined files*/
#include "cli-ops.h"
#include "main.h"
#include "network-check.h"

int main() {
  display_welcome();
  fetchNetInfo();
  return 1;
}
