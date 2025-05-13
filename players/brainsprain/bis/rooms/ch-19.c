inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
  
  short_desc = "Bismarck Hall";
  long_desc =
    "A peasant glances nervously over his shoulder then hurries out of the "+
    "room.  You can faintly hear the dejected sound of moaning coming from "+
    "somewhere to the east.  It is the sound of one who has lost all hope. "+
    "The carpet ends in the center of the room.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-20.c","east",
    br+"/ch-18.c","west",
  });
  items = ({
    "peasant",
    "A nervous little man",
    "room",
    "Part of the northern hall",
    "carpet",
    "A carpet of welcome",
  });
  ::reset(arg);
  replace_program("room/room");

}

