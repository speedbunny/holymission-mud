inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Hall";
  long_desc =
    "Closed and locked doors line the halls here.  From behind several of "+
    "the doors comes the sounds of a party.  Piles of garbage have been "+
    "thrown in the hall and are making a mess.  Here and there is shattered "+
    "glass on the ground.\n";
  items = ({
    "doors",
    "On either side of the hallway there are locked doors",
    "garbage",
    "It seems that the servants have not been keeping up with the garbage detail",
    "glass",
    "There are shards of glass laying all around the floor",
    "floor",
    "It is covered with glass and garbage",
  });
  set_light(1);
  dest_dir = ({
    br+"/ch-10.c","north",
    br+"/ch-8.c","south",
  });
  ::reset(arg);
  replace_program("room/room");
}

