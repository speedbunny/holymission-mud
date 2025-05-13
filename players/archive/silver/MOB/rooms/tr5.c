/*
 Just test room for mob
*/

inherit "room/room";
#include "/players/silver/MOB/defs.h"

reset(arg)
 {
  if(!arg)    /* do the following block only the first time */
   {
    set_light(1);

    short_desc="Mob operation room.",
    long_desc=
"\n" +
"You are int the room on which orc mobs should not look for "+
"a player to capture. They can use this room just for the way home.\n";

 /* lets set the destination directions */

    dest_dir=
     ({
       ROOM + "tr2","south",
       ROOM + "tr4","west",
       ROOM + "tr6","east",
     });

    items=
     ({
"air",
"It's very dry up here",
"floor",
"A bit of sand is everywhere", 
"ceiling",
"It's not too high"
     });

   property =
     ({
              "mob_not_ok"           // *grin*
     });

   smell =
"This place is pretty dusty.";
   }
 }

init()
 {
  ::init();
 }
