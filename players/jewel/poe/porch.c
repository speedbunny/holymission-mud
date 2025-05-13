/* Coded by Jewel of Holy Mission */
/* /players/jewel/poe/porch.c */
 
#include "/players/jewel/defs.h"
#include "/obj/door.h"
 
inherit "room/room"; 
object obj_1, obj_2;
 
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  MAKE_DOORS(
    POE+"porch","north",
    POE+"foyer","south",0,0,
    "Massive wooden door.\nIt is the main door to the House of Usher.\n",
    1,0,0);
  set_light(1);
  property=({"no_teleport"});
  short_desc = "Front porch to the House of Usher";
  long_desc =
  "You are on the front porch of the House of Usher.\n"
+ "The stone porch is crumbling all around you.  Weeds poke through "
+ "the steps leading to the porch, and ivy twists its way up the "
+ "ancient columns which were once so stately.  To the north is the "
+ "entrance door to the house.\n";
  items = ({ 
 "columns","Two ancient and crumbling columns",
 "porch","Crumbling stone porch.  Watch your step",
 "ivy","Dead ivy which once twisted around the columns",
 "steps","Crumbling stone steps.  Weeds are growing in them",
             });
  dest_dir = ({
         POE+"bridge","south",
                });
  smell = "You smell old and rotted ivy here.";
  replace_program("room/room");
}

