/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "East Wing ";
	long_desc = 
"Another twist in the corridor here turns your path north again, to \n"+
"reveal a dazzle of light splayed across the flag-stones of an exit\n"+
"to the west up ahead.  From there, a cold draught blows down the dusty\n"+
"passage-way to you.\n";

	dest_dir = ({
          CROOMS + "ewing10","north",
          CROOMS + "ewing8","east",
        });

    ::reset (arg);

    RPR("room/room");
}

