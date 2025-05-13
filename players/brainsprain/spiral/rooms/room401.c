inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A stairwell";
  long_desc =
"A set of stairs winds up to the next level of the caverns.  Along the "+
"wall of the room the passage tapers down.  The smell of sweat is heavy "+
"in the air.  Flies buzz around the room looking for there next meal.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room313","up",
    sr+"/room402","east",
  });
  items = ({
    "flies",
    "Large flies with no eyes, they seem to have adapted to subterranean living",
  });
::reset(arg);
    replace_program("room/room");
}
