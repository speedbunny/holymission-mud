inherit "room/room";
#include "../asgard.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Asgard land",
    long_desc="You have a view over the famous Asgard land.\n"+
              "You see wide lowlands, a little wood a swamp and\n" +
             "far in the north you see the faint mountainous silhouette\n";
    
    items=({"swamp","It's very foggy today, so you can't say what they exactly look like",
            "mountains","Very faint silhouette...",
            "lowlands","Really really wide"});

    dest_dir =({ROOM + "start001","east",
                ROOM + "asg001","north",
              });

    smell = "You smell the fresh air";
  }
}
