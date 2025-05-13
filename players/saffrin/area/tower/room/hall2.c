inherit "room/room";
#include "/players/saffrin/defs.h"

int move(string str) {
  if(!str || str == "");
    str=query_verb();
  if(str=="north" && !TPWIZ && TPGUILD !=5) {
    ME("A strange force zaps you in the buttocks.\n");
    say("A strange force zaps "+CQN+" in the buttocks.\n");
    return 1;
  }
  if(str=="south" && !TPWIZ && TPGUILD !=5) {
    ME("A strange force zaps you in the buttocks.\n");
    say("A strange force zaps "+CQN+" in the buttocks.\n");
    return 1;
  }
  return ::move(str);
}

reset(arg) {
  set_light(1); 
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "There are several torches fixed to the walls around "+
      "you.  Wonderful scents are coming from the west, teasing"+
      " your nose.  "+
      "The mage mapping room is to the "+
      "north.  From the south, there appears to be a wonderful "+
      "glow, radiating with magic.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  smell="Wonderful smelling herbs are coming from the west.\n";
  property= ({ "has_fire", "no_sneak" });
  items=({ 
      "stairwell","A stairwell for a spiral staircase",
      "staircase","A winding spiral staircase",
      "floor","The floor is tiled with dark, green jade",
      "torches", "Brass torches with flicking flames",
      "flames","Flicking orange flames",
  });
  dest_dir=({
      TOWER+"room/map_room", "north",
      TOWER+"room/donation", "south",
      TOWER+"room/perfume", "west",
      TOWER+"room/hall3", "up",
      TOWER+"room/hall1", "down",
  });
  property=({ "no_sneak" });
  ::reset();
}

init() {
  ::init();
}
