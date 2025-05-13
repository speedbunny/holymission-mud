/*  This is the West side of the Courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Camelot's Courtyard ";
	long_desc = 
"You are standing at the western side of the courtyard of the castle.\n"+
"Here, you can see where the moles have started to dig up the earth in\n"+
"little burrows.\n";

 	dest_dir = ({
          CROOMS + "wcourt3","north",
          CROOMS + "court2","east",
          CROOMS + "wcourt1","south",
         
     });

	items = ({
  "wall",
"This is the stone wall, presumably of the West Wing of Camelot",
  "burrows",
"These are little mounds of earth, which have been dug up by moles", 
     });
}

init() {
  ::init();
  add_action("search","search");
}

search (str) {

  if(str != "burrows") 
   return NFAIL("That is not here to search.\n");

  write("You succeed in finding a little hole which the moles have created,\n"+ 
        "into which you promptly fall in!!\n");  
  say(TPN+" snoops around the burrows of dirt, and immediately disappears!!\n");

  MPL("down a small hole#/players/tamina/castle/rooms/hole1");

   return 1;

}
