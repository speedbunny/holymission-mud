inherit "room/room";
#include "../walhalla.h"

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

    dest_dir =({ROOM+"floor13","southeastdown",
                ROOM+"up2","northeastup"});

    smell = "It smells very unnatural in here.";
  }
}
init()
{ if(random(TP->query_dex())<=random((TP->query_dex())/5))
  { write("You fall onto you butt and roll down the stairs.\n");
    TP->reduce_hit_point(TP->query_hp()/50);
    transfer(TP,ROOM + "floor13");
    return 1;
  }
  ::init();
}
