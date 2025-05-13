/*  This is the Crossroads at the North Corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "North Junction";
	long_desc = 
"You pass again into the darkness that sadly reminds you of the depressing\n"+
"earlier passages of Camelot.  Here, you stand at a four-way junction, with\n"+
"corridors leading off in the four cardinal points of the compass.  Ahead,\n"+
"to the north, you can see your light-source reflecting off various metallic\n"+
"surfaces.  Empty, dark passages lead off to the east and west.  The south\n"+ 
"passage will of course take you back to the Quadrangle.\n";

	dest_dir = ({
          CROOMS + "alchemy","north",
          CROOMS + "n_cloister","south",
          CROOMS + "ncorridor2","east",
          CROOMS + "ncorridor1","west",
        });

    ::reset (arg);

    RPR("room/room");
}
