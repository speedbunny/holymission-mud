inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  if(!present("wheel",TO)) MO(CO(PM+"items/wheel"),TO);
  if(!arg)
  {
    set_light(1);
    short_desc="Inside tent";
    long_desc=
      "\You are inside one of the tents at the bazaar.  This simple green\n\
tent encompasses a small area, just enough room for a few people and a\n\
mysterious wheel sitting in the center.\n";
    dest_dir=({
      PM+"tower/bazaar","south",
    });
  }
  ::reset();
  replace_program("room/room");
}
