inherit "room/room";

#include "/players/tamina/defs.h"

object dummy;

void reset(int arg) 
{
  dummy = present("dummy");
  if (!dummy)
  {
    dummy = CLO(TEDS + "dummy");
    MO(dummy, TO);
  }
  if (arg) return 0;

    set_light(1);
    short_desc = "Tamina's Testing Area";
    long_desc = 
"This is where Tamina tests things...\n";

    ::reset(arg);
    RPR("room/room");
}

