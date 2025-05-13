inherit "room/room";

#include "/players/tamina/defs.h"

object basilisk;

void reset(int arg) 
{
  basilisk = present("basilisk");
  if (!basilisk) 
  {
    basilisk = clone_object(TMONS + "basilisk");
    "/players/tamina/teds/random_treasure"->make_item(basilisk, 28);
    "/players/tamina/teds/random_magic"->make_item(basilisk, 28);
    move_object(basilisk, this_object());
  }
  if (arg) return 0;

  set_light(1);
  short_desc = "Dread Forest";
  long_desc =
"The undergrowth here has been rooted up and trampled.\n"+
"Gouge marks as if from large tusks score the ground\n"+
"and hoofprints can be seen in the softer soil.\n"+
"To the east, you see a large cliff wall barring any passage.\n";

    dest_dir = ({
    TFOREST + "rm6", "north",
    TFOREST + "rmW", "south",
    TFOREST + "rm1", "west",
    });
}

