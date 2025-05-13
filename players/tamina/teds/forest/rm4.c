inherit "room/room";

#include "/players/tamina/defs.h"

object satyr;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"You are wandering through the edges of the Petrified Forest.\n"+
"Light streams through the tall trunks of the trees, making\n"+
"a very calming, placid area here.\n";

    dest_dir = ({
    TFOREST + "rm7", "north",
    TFOREST + "rmZ", "south",
    TFOREST + "rm3", "west",
    });

  satyr = present("satyr");
  if (!satyr) 
  {
    satyr = clone_object(TMONS + "satyr");

    "/players/tamina/teds/random_magic"->make_item(satyr, 27);
    "/players/tamina/teds/random_magic"->make_item(satyr, 28);
    "/players/tamina/teds/random_magic"->make_item(satyr, 29);
    move_object(satyr, this_object());
  }
}
