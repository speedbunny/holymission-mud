inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  
  short_desc = "Phospholuminent fungus room";
  long_desc =
    "A pale green light illuminates the granite walls of this chamber.  Further "+
    "inspection reveals that the light comes from a green fungus covering "+
    "most of the walls.  Small pebbles are strewn all over the room.\n";
  set_light(1);
  dest_dir = ({
    sr+"/room107","northwest",
    sr+"/room109","southeast",
  });
  items = ({
    "light",
    "It is coming from the fungus",
    "walls",
    "The walls are made of granite with tiny reflective surfaces",
    "fungus",
    "A green fungus that emits a pale light",
    "pebbles",
    "Pebbles ranging in size from quarter inch to one inch",
  });
  ::reset(arg);
  replace_program("room/room");
}

