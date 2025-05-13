inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
    if(arg)
        return;

  short_desc = "Cracked walls";
  long_desc =
"The darkness slowly envelops you as you walk through the cave.  Several "+
"large cracks run the length of the wall.  They branch and form an fine, "+
"intricate pattern.  Small, animal footprints mar the smooth finish of the "+
"dust covering the floor.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room102","east",
    sr+"/room104","southwest",
  });
  items = ({
    "footprints",
    "These small footprints look like they might have been made by rats feet",
    "cracks",
    "Time and weight have caused the walls to crack",
    "cave",
    "The cave rumored to house the downward spiral",
    "walls",
    "It must have taken years to cut these walls from the living stone",
  });
    ::reset(arg);
    replace_program("room/room");
}
