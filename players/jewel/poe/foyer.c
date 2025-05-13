/* Coded by Jewel of Holy Mission */
/* /players/jewel/poe/foyer.c */

#include "/players/jewel/defs.h"

inherit "room/room"; 

reset(arg)
{
  ::reset(arg);
  if(!present("butler"))
   {
     MOVE(clone_object(POEM+"butler.c"),TO);
     }
  if (arg) return;
  set_light(1);
  property=({"no_teleport"});
  short_desc = "Foyer";
  long_desc =
  "You are in the foyer of the House of Usher.\n"
+ ""
+ ""
+ ""
+ ".\n";
  items = ({ 
  "","",
  "","",
  "","",
  "","",
             });
  dest_dir = ({
         POE+"porch","south",
         POE+"?","north", 
                });
  smell = "You smell the putrid air which drifts in from outside.";
}
