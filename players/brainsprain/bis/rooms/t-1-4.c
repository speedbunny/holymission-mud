inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "The room of death";
  long_desc =
    "This room is painted black.  All the windows are covered with thick "+
    "black drapes.  In the center of the is a pool of water.  Candles "+
    "surround it and dance with an unnatural light.  Several coffins "+
    "are stacked all about the room.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-1-3.c","down",
  });
  items = ({
    "water",
    "A scrying pool",
    "light",
    "It casts a spooky glow around the room",
    "room",
    "The princesses abbatoir"
    "windows",
    "A window covered in a thick drape",
    "drapes",
    "Thick black drapes",
    "coffins",
    "The object of necromantic passions",
    "pool",
    "A pool of water",
    "candles",
    "Wax candles",
  });
  
  clone_list = ({ 1, 1, "princess", bm+"/bitch.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}

