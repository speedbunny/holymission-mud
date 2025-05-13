inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The road here is beginning to degenerate.  Weeds have grown up "+
    "through the cobbles.  In some places the winter frost has shattered "+
    "the cobbles.  Floating over the ocean to the south is the duel room, "+
    "where are disputes in Towpath are handled.  Unfortunately, the duel "+
    "room has been closed due to insurance rates.\n";
  set_light(1);
  items = ({
    "ocean",
    "The Pansiac ocean",
    "room",
    "The duel room, it is currently closed",
    "duel room",
    "It is currently closed",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "weeds",
    "Dandelions forcing there way through the road",
    "cobbles",
    "Shattered hunks of rocks",
  });
  dest_dir = ({
    br+"/tr-12","west",
    br+"/tr-14","east",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}

