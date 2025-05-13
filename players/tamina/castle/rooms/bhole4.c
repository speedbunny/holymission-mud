/*  This is a hole under the Bed  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) 
{
  if (arg) return ;

      	set_light(-2);
	short_desc = "A Darkened Chamber";
	long_desc = 
"You hae just entered what appears to be the end of this small,\n"+
"dark tunnel under the bed.  There are no more visible exits from\n"+
"this room, apart from the one behind you.  The room seems to be \n"+
"rather bare, except from the opened cage against a wall, and a \n"+
"small pile of bones beside the cage.\n";

	dest_dir = ({
          CROOMS + "bhole3","south",
        });

	smell = "You smell wet, animal odours, and tangled fur...\n";

	items = ({
  "cage",
"It is a rather large, iron cage, with an opened front",
  "walls",
"Just as you would expect: walls",
  "bones",
"They are of varying sizes, but from what you would guess are mainly humans",
    });

    clone_list = ({1, 1, "thing", "/players/tamina/castle/monsters/thing", 0, }); 

    ::reset();
  
    RPR("room/room");
}
