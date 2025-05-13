inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Banner room";
  long_desc =
"Dozens of banners line the walls of this room.  Each banner has a "+
"different insignia denoting a family or clan.  In the center of the.  "+
"western wall is a huge flag.  The floor is covered in old, dirty, rugs.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room501","northwest",
    sr+"/room503","east",
  });
  items =({
    "banner",
    "This particular banner displays and orc standing over its fallen victim",
    "banners",
    "They display the insignia's of different family and clans",
    "flag",
    "This huge banner displays an orc standing proud with a scepter in hand",
  });
  ::reset(arg);
    replace_program("room/room");
}
