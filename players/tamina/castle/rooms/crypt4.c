/*  This is the Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "A Crypt under Camelot";
	long_desc = 
"You enter an adjoining passage-way, between the two chambers of the\n"+
"Crypt of Camelot.  Ahead, to the north, you can see a larger chamber\n"+
"than that which can be seen to the south.\n";

	dest_dir = ({
          CROOMS + "crypt6","north",
          CROOMS + "crypt2","south",
        });

    ::reset (arg);

    RPR("room/room");
}

