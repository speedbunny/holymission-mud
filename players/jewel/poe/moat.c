/* Coded by Jewel of Holy Mission */
/* /players/jewel/poe/moat.c */
 
#include "/players/jewel/defs.h"
 
inherit "room/room";
 
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Moat";
  long_desc = 
  "Ugh!  You fell into the moat!  You are wading in chest-high\n"
+ "black muck.  This stuff really stinks!  The walls are blackened\n"
+ "with this substance.  Oh no! The muck level starts to rise!\n";
  items = ({ 
"moat","A chasm around the castle filled with a black liquid",
"muck","It is black and very icky.  The stench is overwhelming",
"wall","Outside wall of the castle.  There are some cracks for climbing",
"walls","Outside walls.  In one there are some cracks for climbing",
"bridge","A stone bridge in ill-repair.  You wish you were back there",
"castle","A gloomy castle.  You wish you were inside instead of here",
             });
  smell = "A repugnant smell of death and decay is strong here.";
}
 
init()
{
  ::init();
  add_action("climb","climb");
}
 
climb(str)
{
  if (str=="wall")
  {  
    write("You huff and puff and climb out of the moat.\n");
    MOVEP("climbs out of the moat#players/jewel/poe/bridge");
    return 1;
    }
  else
  {
   write("What do you want to climb?\n");
   return 1;
    }
}

