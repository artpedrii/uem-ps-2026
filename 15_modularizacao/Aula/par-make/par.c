#include <stdio.h>

#include "par.h"

Par soma_par(Par x, Par y) {
  Par r = {x.a + y.a, x.b + y.b};
  return r;
}

void mostra_par(Par z) {
  printf("[%i %i] \n", z.a, z.b);
}
