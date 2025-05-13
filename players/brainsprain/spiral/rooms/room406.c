inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A pearl shaped cavern";
  long_desc =
"The room is vaguely pearl shaped and colored.  The constant plop of "+
"dripping water is easily heard.  To the northwest an indistinct sound "+
"can be heard.  Small stones litter the floor.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room405","southeast",
    sr+"/room407","northwest",
  });
items = ({
  "stones",
  "Pebbles strewn about the room",
      });
  ::reset(arg);
    replace_program("room/room");
}
