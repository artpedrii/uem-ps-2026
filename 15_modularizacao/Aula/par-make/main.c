#include <stdio.h>

#include "par.h"

int main() {

  Par p1 = {1, 2};
  Par p2 = {4, 7};
  mostra_par(p1);
  mostra_par(p2);
  Par r;
  r = soma_par(p1, p2);
  mostra_par(r);

  return 0;
}
