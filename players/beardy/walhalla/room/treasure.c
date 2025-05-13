inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Treasure room",
    long_desc="This is the hidden Treasure room of Walhalla. Perhaps the\n" +
              "have some money or not for you this time. But be aware Wotan\n" +
              "might be around here.\n";


    property =({"no_teleport","no_hide","no_sneak"});

    dest_dir =({ROOM + "cat6","northeastup"});

    smell = "You smell the big treasure";

    CM("wotan");
  }
}
