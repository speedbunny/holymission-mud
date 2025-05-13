 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

object serp;
  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
       "You are in a dark tunnel filled with evil. The walls "+
       "are blackened and charred with gouges torn out of them. "+
       "It is roomy and the ceiling is obscured by the darkness.\n",65);
property=({"no_teleport","no_sneak"});
   items=({"walls","The walls are charred.",
           "floor","The floor is burned and gouged from what looks like claws."});

 if(!serp)
   serp=clone_object("/players/tatsuo/ishikawa/monsters/serpent1");
   move_object(serp, this_object());
dest_dir=({CPATH+"c28","south",CPATH+"c30","north"});
}
