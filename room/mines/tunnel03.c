inherit "/room/room";

#include <room_defs.h>

static status rope;

int move(string str) {
  if(!str)
    str = query_verb();

  if(str=="down" && !rope) {
    write("You would fall down the hole and possibly hurt yourself.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;

  set_light(0);
  short_desc = "Hole";
  long_desc =
    "There is a big hole here, and some kind of iron ring in the wall. "+
    "@@extra_look@@It is quite easy to pass around the hole.\n";

  dest_dir = ({
    MINES + "tunnel04", "north",
    MINES + "tunnel02", "south",
    MINES + "tunnel08", "down",
  });

  items = ({
    "ring", "A sturdy iron ring, fastened to the wall",
    "rings", "A sturdy iron ring, fastened to the wall",
    "iron ring", "A sturdy iron ring, fastened to the wall",
    "tunnel", "It is dark",
    "hole", "It is large enough for an ogre to climb down",
    "wall","A sturdy iron ring has been firmly attached to the cave wall",
  });

  rope = 0;
}

string extra_look() {
  if(rope && present("rope", TO))
    return "There is a rope tied to the ring hanging into the hole. ";
  return "";
}

int tie(string str) {
  if(str=="tunnel" || str=="hole")
    return 0;

  if(!rope) { 
    rope = 1;
    return 1;
  }
  return 0;
}

int untie(string str) {
  if(rope) {
    rope = 0;
    return 0;
  }
  return 1;
}

nomask int query_rope() {
  return rope;
}

