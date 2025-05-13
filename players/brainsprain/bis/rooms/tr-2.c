inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "A well maintained road";
  long_desc =
    "The road here is half cobblestones and half dust.  Dust plumes up and "+
    "curls around you ankles as you walk.  Traffic is so thick here that "+
    "you have to shoulder your way through the crowd.  To the west is a "+
    "four way intersection.\n";
  set_light(1);
  items = ({
    "dust",
    "It plumes up and curls around your ankles as you walk",
    "traffic",
    "There are a lot of people here",
    "crowd",
    "People leaving and entering Towpath",
    "intersection",
    "The main intersection in Towpath",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "cobblestones",
    "The road is made of cobblestone",
  });
  dest_dir = ({
    br+"/tr-3","west",
    br+"/town_road1","east",
  });
  rnd = 6+random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  
  replace_program("room/room");
}
