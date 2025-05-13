inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Hall";
  long_desc =
"The lighting increases drastically in this room due to the large stained-"+
"glass window on its northern wall.  The window depicts placid scenes of "+
"at court.  A thick, red, plush carpet runs the length of this room.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-16.c","east",
    br+"/ch-14.c","west",
  });
items = ({
  "wall",
  "The northern wall of Castle Bismarck",
  "lighting",
  "It is caused by the stained glass window on the northern wall",
  "room",
  "A section of the northern hallway of Castle Bismarck",
  "bismarck",
  "Castle Bismarck",
  "castle",
  "Castle Bismarck",
  "carpet",
  "The red carpet of welcome",
  "window",
  "A stained glass window depicting life at court",
});
::reset(arg);
  replace_program("room/room");

}

