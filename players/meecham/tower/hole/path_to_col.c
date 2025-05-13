inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc="Path leading down";
    long_desc=
      "You are on a dark path sloping steeply downward.  It looks as if there\n\
are several set of footprints leading down, but none leading up...\n";
    dest_dir=({
      PM+"tower/entrance","up",
      PM+"tower/hole/cols_room","down",
    });
  }
  ::reset();
  RR;
}
