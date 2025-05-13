inherit "room/room";

#include "/players/jake/defs.h"

reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "Entering the pasture";
 long_desc = "You are standing in a small horse pasture.  Directly south of\n" +
             "you is the stables in which the castle horses are kept, and just\n" +
             "beyond the stables is the huge goblin castle.  Looking around\n" +
             "you begin to wonder what would stop anyone from attacking from\n" +
             "back here, as opposed to the front of the castle.  Maybe the goblins\n" +
             "have enough of a reputation that nobody dares to attack?\n";
 items = ({
  "stables","The stables that the castle's horses are kept in",
  "castle","The goblin castle",
  });
 DD = ({
  CAS + "s9","south",
  CAS + "p2","northwest",
  CAS + "p3","northeast",
  });
replace_program("room/room");
}
