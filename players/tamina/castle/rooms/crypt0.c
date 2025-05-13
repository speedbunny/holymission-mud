/*  This is */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "The Crypt";
	long_desc = 
"You have finished coming down the long set of cold stone stairs\n"+
"to find yourself in a very dark, dusty, smelly crypt.  Ahead to the\n"+
"north can be seen the chambers which have been manually hollowed \n"+
"out from the stone and rock.\n";

	dest_dir = ({
          CROOMS + "crypt2","north",
          CROOMS + "crypt","up",
        });

	items = ({
  "crypt",
"You have finished coming down the long set of cold stone stairs "+
"to find yourself in a very dark, dusty, smelly crypt.  Ahead to the "+
"north can be seen the chambers which have been manually hollowed "+
"out from the stone and rock",
     });

    ::reset (arg);

    RPR("room/room");
}
