inherit "/obj/treasure";
#include "/players/mangla/defs.h"

void reset(int arg) {
}

init() {
  if(TP->LEVEL > 0 && TP->query_interactive())
    destruct(TO);
}
