#include "/players/redsexy/guild/obdefs.h"

id(arg) {
  return arg == "trident";
}

short() {
  return "Trident (wielded)";
}

long() {
  write("This is the trident of a Triton.\n");
}

get() { return 1; }
     
drop() {
  destruct(TO);
  return 1;
}
