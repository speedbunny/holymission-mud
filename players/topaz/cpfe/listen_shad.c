#include "/players/matt/defs.h"

object master;

void start_shad(object obj) {
  master = obj;
  shadow(master, 1);
}

catch_tell(str) {
  string dummy1;
  string dummy2;
  object dude;

  if(master) {
    if(sscanf(str, "%s tells you: %s", dummy1, dummy2) == 2) {
      dude = find_player(LOW(dummy1));
      if(dude) TELL(dude, master->NAME + " cannot hear you now.\n");
      return str;
    }
    else if(sscanf(str, "%s shouts: %s", dummy1, dummy2) == 2)
      return str;
    else write(str);
  }
  return str;
}
