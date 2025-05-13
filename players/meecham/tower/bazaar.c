inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Bazaar";
    long_desc=
      "\A bazaar is being setup here in a larger clearing.  So far, three\n\
tents seem to be open for business, one to the north, one to the west,\n\
and one to the south.\n";
    items=({
      "tents","There are three tents, north, south, and west",
    });
    dest_dir=({
      PM+"tower/wheel_tent","north",
      PM+"tower/keg_shop","west",
      PM+"tower/entrance","east",
      PM + "pot_shops/ps_meecham","south"
    });
  }
  ::reset();
  replace_program("room/room");
}
