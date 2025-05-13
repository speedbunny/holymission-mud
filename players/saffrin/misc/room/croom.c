inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Saffrin's Coding Room";
  long_desc = 
      "This is Saffrin's exitless code room for the purpose of working on areas.\n";
  property=({
      "no_teleport",
  });
  ::reset();
  replace_program("room/room");
}
