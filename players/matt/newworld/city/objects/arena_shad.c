#include "/players/matt/defs.h"

#define ARENA (NWCITY + "rooms/arena")

object master;

void start_shadow(object obj) {
  master = obj;
  shadow(master, 1);
}

int hit_player(int dam, int type) {
  if(dam >= master->HP) {
    ARENA->end_battle(ARENA->query_other_glad(master));
    return 1;
  }
  else return master->hit_player(dam, type);
}


