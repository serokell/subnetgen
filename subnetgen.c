#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint8_t subnetgen_random_uint8() {
  uint8_t n;
  assert(!getentropy(&n, sizeof(n)));
  return n;
}

#define SUBNETGEN_MASK "10.%u.0.0/16"

int main() {
  printf(SUBNETGEN_MASK "\n", subnetgen_random_uint8());
}
