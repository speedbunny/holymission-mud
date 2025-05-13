inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
    if(arg)
        return;

  short_desc = "Stack of wood";
  long_desc =
"  Something or someone has stacked a large pile of wood against the western\n"+
"  wall.  Several logs have rolled into the center of the room.  Sawdust\n"+
"  covers the ground.  A humming sound comes from behind the stack of\n"+
"  logs.\n"+
"\n";
  set_light(0);
  dest_dir = ({
    sr+"/room104","northeast",
    sr+"/room106","south",
  });
items = ({
  "wood",
  "A huge pile of wood",
  "logs",
  "Several oak trees that have been cut down and brought here",
  "pile of wood",
  "A massive stack of oak, maple, ash, and cedar logs",
  "sawdust",
  "sawdust left over from cutting the trees down",
});
    ::reset(arg);
    replace_program("room/room");  
}
