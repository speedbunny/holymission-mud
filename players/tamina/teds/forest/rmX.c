inherit "room/room";
  object ob;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

      	set_light(0);
	short_desc = "In a very dark Cave";
	long_desc = 
"As you step into the cave, the light around you suddenly disappears,\n"+
"as the darkness of the cave overwhelms you.  It is quite cold in here,\n"+
"with a slight breeze wafting through the entrance behind you.  There \n"+
"very little to see in this cave, apart from a pile of furs to one\n"+
"side, and a pile of yellowed bones beside them.\n"+

	smell = "It smells very natural, very earthy in here.\n";

        dest_dir = ({
    TFOREST + "rmR", "south",
    TFOREST + "rmW", "west",
    });

	items = ({
  "bones",
"These are old, yellowed bones, some gnawed at both ends, with brittle, "+
"ragged ends, glinting in the little light that there is",
  "furs",
"These are different furs of various animals, which probably belonged to "+
"the owners of the bleached bones",
     });

  ob = present("bear");
  if (!ob || !living(ob))
  MO (CLO (CMONS + "bear"), TO);
}
