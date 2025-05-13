inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "To the north is a door with a heavy iron bar across it.  At the end of "+
    "the bar is a thick iron lock.  The walls around the door have strange "+
    "symbols painted on them.  A massive pennant atop the southern wall "+
    "flaps in the gentle breeze.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-6.c","west",
    br+"/ch-4.c","east",
  });
  items = ({
    "wall",
    "The southern wall, atop which a pennant flaps in the breeze",
    "walls",
    "Castle walls made from rough hewn stone",
    "stone",
    "Rough hewn stone that composes the castle walls",
    "door",
    "A massive oaken door",
    "bar",
    "A huge iron bar locking the door",
    "lock",
    "A massive lock designed to keep out prying eyes"
    "symbols",
    "Magic runes",
    "pennant",
    "A huge pennant declaring Count Bismarck the winner in the joust competition",
  });
  ::reset(arg);
  replace_program("room/room");
}

