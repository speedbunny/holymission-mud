/*  This is a secret passge down a well  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(-2);
	short_desc = "Down a Well";
	long_desc = 
"You are in a tiny passageway leading from the well in the courtyard\n"+
"of Camelot, to the north.  Behind you is a very small hole in the wall.\n"+
"There is water pouring in through the small hole at occasional moments,\n"+
"creating a strange, eerie dripping noise.\n";

	dest_dir = ({
          CROOMS + "well3","northeast",
        });

	items = ({
  "hole",
"Perhaps if you are small enough, you will end up in the interior of the "+
"well if you enter it",
  "water",
"Just as filthy as you'd expect",
  "walls",
"From the little light that you have, you can see that these are well-"+
"crafted stone walls, made to stand the test of time",
  "passageway",
"You are walking along a small tunnel, underneath the ground",
  "passage",
"You are walking along a small tunnel, underneath the ground",
     });

}

init() {
  ::init();
  add_action("enter_it", "enter");
}

enter_it (arg) {

  if (arg == "hole") {
    if (TP->query_size() != 1) {
      write("You are far too large to enter here!\n");
      say(TPN+" desperately tries to squeeze into the small hole!\n");
  } else {
      write("You nimbly hop through the small hole\n");
      MPL("through the small hole#/players/tamina/castle/rooms/well1");
  }

  return 1;

  }

}

