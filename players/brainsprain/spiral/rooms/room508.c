inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark room";
  long_desc =
"This rooms acoustics make it so that your footsteps sound like thunder "+
"and your breathing echos around the room.  The dust on the floor is "+
"broken up everywhere by four-toed footprints.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room509","west",
    sr+"/room507","southeast",
  });
  items =({
    "footprints",
    "orc footprints",
 });
  ::reset(arg);
    replace_program("room/room");
}
