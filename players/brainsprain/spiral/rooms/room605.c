inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A long hallway";
  long_desc =
"Crudely shaped gargoyles peer out at you from the walls.  The walls "+
"are smooth and have obviously been cleaned recently.  Several stones lay "+
"in the center of the room.  The southern wall is made up of a massive "+
"rockslide.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room606","northeast",
    sr+"/room604","west",
  });
  items =({
    "gargoyles",
    "Stone gargoyles with sneers on their faces",
    "stones",
    "Stones arranged in an obscure pattern",
  });
  ::reset(arg);
    replace_program("room/room");

}
