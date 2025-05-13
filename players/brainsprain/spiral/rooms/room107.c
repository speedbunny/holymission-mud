inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  
  short_desc = "A dark room";
  long_desc =
    "Carcasses are all over the floor of this room.  Bones of long dead "+
    "rats crumble under your feet as you walk. The smell of decay is "+
    "overpowering.  A faint glow comes from the southeast.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room106","north",
    sr+"/room108","southeast",
  });
  items = ({
    "glow",
    "It looks like it gets lighter to the southeast",
    "floor",
    "The floor of this room",
    "room",
    "An underground cavern",
    "bones",
    "Several collections of delicate rat bones",
    "carcasses",
    "Half-eaten carcass which are so mauled that they are unidentifiable",
  });
  clone_list = ({ 1, 1, "badger", sm+"/badger.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}
