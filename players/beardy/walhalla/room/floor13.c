inherit "room/room";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Stairhouse",
    long_desc="You see lots of small stairs and think you\n" +
              "are in a hughe stairhouse. It's very cold and at\n" +
              "a strong wind blows in here\n";

    items=({"stairs","What huge ones !",
            "wind","HUI.... It's gone..."});

    property =({"no_sneak","no_hide","no_teleport"});

    dest_dir =({ROOM+"floor11","south",
                ROOM+"up1","northwestup"});

    smell = "It smells very unnatural in here.";
  }
}
