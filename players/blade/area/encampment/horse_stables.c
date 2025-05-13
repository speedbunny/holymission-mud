inherit "room/room";

#include "/players/blade/area/blade_defs.h"
inherit ROOM_FUNCTS ;

reset(arg){

   if(!arg) {
        set_light(1);
        short_desc="The horse stables";
        long_desc=
"You are in the horse stables.  Horses in wooden stalls surround you.\n"+
  "The hard ground is covered with straw, and on a small table in the\n"+
  "corner you notice some tools.  On the northern wall hangs feedbags,\n"+
  "and other types of tools.  You hear banging noises to the north.\n";
   dest_dir=({
            CAMPPATH+"blacksmith.c", "north",
	    CAMPPATH+"encampment3.c","west",
                 });
   items=({ 
    "table","A sturdy table with tools on top of it.",
  });
        smell = "You smell horses.";
      } 


}












