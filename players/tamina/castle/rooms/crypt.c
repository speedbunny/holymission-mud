/*  This is a room  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "At the top of stairs, leading down to a Crypt";
	long_desc = 
"An arched door is in front of you here, with a set of\n"+
"stone stairs leading downwards beyond the archway.  The\n"+
"darkness down the stairs looks even more thicker and \n"+
"substantial than before...\n";

	dest_dir = ({
          CROOMS + "ncorridor1","east",
          CROOMS + "crypt0","down",
        });

	items = ({
  "door",
"A solid oaken door, on huge iron hinges, and a strong iron lock.  "+
"On looking at the ground below the door, you can see that there is a "+
"clear layer of dust lying there, untouched",
  "stairs",
"Old stone stairs covered in dust, leading down into the depths of"+
"Camelot",
     });

    ::reset (arg);

    RPR("room/room");
}
