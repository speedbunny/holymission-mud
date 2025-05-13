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
"You are int the room on which orc mobs operates freely to find "+
"a player to capture. This is just test version of the mob and "+
"are is build for test purposes only as well."+
"\n";

 /* lets set the destination directions */

    dest_dir=
     ({
       ROOM + "tr8","south",
       ROOM + "tr10","east",
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
       "mob_ok"
     });

   smell =
"This place is pretty dusty.";
   }
 }

init()
 {
  ::init();
 }
