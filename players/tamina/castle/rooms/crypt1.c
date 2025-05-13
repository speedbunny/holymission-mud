/*  This is the Crypt  */

inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(-1);
    short_desc = "A Crypt under Camelot";
    long_desc = 
"You creep stealthily into one of the minor recesses in the Crypt.\n"+
"Strangely, there is nothing of interest here, simply the clawed-out\n"+
"cave in which you stand.\n";

    dest_dir = ({
          CROOMS + "crypt2","east",
        });

    clone_list = 
  ({ 1, 1, "scorpion", CMONS + "scorpion", 0, });

    ::reset();

    RPR("room/room");

}

