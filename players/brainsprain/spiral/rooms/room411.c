inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Barren Room";
  long_desc =
"This room is completely barren of any form of litter.  It looks as if the "+
"the walls have been scrubbed clean.  There is absoulutely no dust on the "+
"floor.  The floor is made up of limestone and several sections contain "+
"fossils of long dead creatures.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room412","southeast",
    sr+"/room410","north",
  });
  items = ({
  "fossils",
  "Bones of long dead creatures",
});
  ::reset(arg);
    replace_program("room/room");
}
