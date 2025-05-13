#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

     set_light(0);
     short_desc = "West Wing ";
     long_desc = 
   "The murky sunlight that filtered into the courtyard is suddenly gone\n"+ 
   "when you enter the darkened corridor.  The darkness does not seem\n"+
   "natural to you...  You are glad however for your light, which is\n"+ 
   "casting strange shadows against the walls.  On the walls themselves\n"+
   "are the rotten remains of old, old tapestries, hanging limply on the \n"+
   "grimy walls.  The corridor itself stretches on into the gloomy north.\n"+
   "To your left, you can see what seems to be a store room of sorts.\n";
     
       dest_dir = ({
   CROOMS + "wcorridor","north",
   CROOMS + "wcourt1","east",
   CROOMS + "store_room","enter",
     });
 
	items = ({
  "tapestries",
"Large artworks hanging on the walls, depicting with good clarity scenes "+
"from what must have been battles fought and won by Arthur and his Knights",
  "walls",
"These are very dirty, and very black in the darkness",
      });

    ::reset (arg);

    RPR("room/room");
}
