#include "/players/redsexy/guild/obdefs.h"

id(arg) {
  return arg == "sword" || arg == "wind sword";
}

short() {
  return "Wind Sword (wielded)";
}

long() {
  write("This is the Wind Sword of a Djinn.\n");
}

get() { return 1; }
     
drop() {
  destruct(TO);
  return 1;
}
