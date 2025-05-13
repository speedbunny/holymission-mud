inherit "room/room";
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The legionnaire guard's quarters",
        long_desc=
"This room cointains twenty-six staggered bunk beds and a fireplace in the\n"+
"southeast corner of the room.  There are four chairs and a table nearby.\n"+
"A door in the south wall leads to the guard captain's quarters.  At the\n"+
"foot of each bed are two padlocked wooden chests.\n";
   dest_dir=({
	    CAMPPATH+"legionnaire_corridor3.c","west",
	    CAMPPATH+"guard_captain_quarters.c","south",
         });
   items=({
  "wall","It was chipped out of stone",
  "bunk beds","Pairs of beds stacked upon each other",
  "fireplace","A fire rages in it, lighting and heating the room",
  "table","A small table with soap and a bucket of water on it",
  "chairs","Four worn chairs surround a small table",
  "chests","Sturdy wooden chests that lie at the end of every bed",
  "scrolls","Wolfen notations about proposed tunnes and rock samples",
  });

    property=({"has_fire"});

        smell = "You smell nothing special.";
    }
}



