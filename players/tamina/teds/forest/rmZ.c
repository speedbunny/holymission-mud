inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if(arg) return 0;
  set_light(1);
  short_desc = "Dread Forest";
  long_desc =
"You enter the Dreaded Petrified Forest surrounding Camelot.\n"+
"The trees crowd together here, all most cutting off all\n"+
"light. Strange howls and gutteral chanting can be heard\n"+
"to the west.\n";

    dest_dir = ({
    TFOREST + "rm4", "north",
    TFOREST + "rmU", "south",
    "/players/emerald/perilous/path/green","east",
    TFOREST + "rmY", "west",
    });

    ::reset();
    replace_program("room/room");
}
