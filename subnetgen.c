#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

uint8_t subnetgen_random_uint8() {
  uint8_t n;
  assert(!getentropy(&n, sizeof(n)));
  return n;
}

#define SUBNETGEN_IPV4_MASK "10.%u.%u.0/24"
#define SUBNETGEN_IPV6_MASK "fd%x:%x%x:%x%x::/48"

int main(int argc, char *argv[]) {
  for (;;)
    switch (getopt(argc, argv, "46")) {
    case '4':
      printf(SUBNETGEN_IPV4_MASK "\n",
             subnetgen_random_uint8(),
             subnetgen_random_uint8());
      break;
    case '6':
      printf(SUBNETGEN_IPV6_MASK "\n",
             subnetgen_random_uint8(),
             subnetgen_random_uint8(),
             subnetgen_random_uint8(),
             subnetgen_random_uint8(),
             subnetgen_random_uint8());
      break;
    case -1:
      return EXIT_SUCCESS;
    default:
      return EXIT_FAILURE;
    }
}
