inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A Sloped Room";
  long_desc =
"The slope of the floor has has lessened a little bit and you would "+
"be able to walk a little steadier if it were not for the loose gravel "+
"on the floor.  The walls are covered in globs of some red substance.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room509","northeast",
    sr+"/room511","southwest",
  });
  items =({
    "gravel",
    "Loose gravel that makes it hard to walk straight",
    "substance"
    "Red paint blobed all over the walls",
 });
  ::reset(arg);
    replace_program("room/room");
}

