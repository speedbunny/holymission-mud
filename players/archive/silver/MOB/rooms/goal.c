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

    short_desc="Mob goal room.",
    long_desc=
"\n" +
"This is the goal room of the orc mob. Here they should decide what "+
"to do with captured players and here they should finish their "+
"wondering as well. Just for test purposes only as well."+
"\n";

 /* lets set the destination directions */

    dest_dir=
     ({
       ROOM + "tr1","north",
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
