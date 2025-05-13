#include "/players/ambrose/defs.h"

inherit "room/room";


void reset(int arg)
 {
  ::reset(arg);
  if(!present("guard")){
  MOVE(clone_object("/players/ambrose/avalon/monsters/sguard"),TO);
  }
    if(arg)
       return;
      set_light(1);
      short_desc="Crossroad";
      long_desc=
"You have reached a crossroads.  To the left you can see a street with\n"
+"a few signs for the local shops.  To the right you see homes of the\n"
+"ordinary variety.  The street ahead seems to be lined with homes of a\n"
+"more expensive type.  Farther down the street you see the cathedral\n"
+"which dominates this city.\n";
      property=({"no_teleport"});
      dest_dir=({
                "/players/ambrose/avalon/city/room1","south",
                "/players/ambrose/avalon/city/room3","west",
                "/players/ambrose/avalon/city/room4","east",
                "/players/ambrose/avalon/city/room5","north",
      });
      items=({
      "room","You need to make it into something!",

           });
       smell="Does'nt smell like anything.";
     }


