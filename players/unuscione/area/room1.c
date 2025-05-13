inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"

reset(arg){
 if (arg) return;
 set_light(1);
 short_desc="Dungeon of Hilo";
long_desc=break_string("You are in a dark musty corridor leading north and south. "+
	   "A ladder is set into the east wall leading up to a trapdoor "+
           "in the ceiling.  Many small footprints lead of in both "+
	    "directions.\n",65);
items=({"corridor", long_desc,
	"ladder", "It goes up",
	"trapdoor","It may lead to the surface",
	"footprints","The footprints have small claw marks, definitly not kender",
	"directions","You know, north, south, east, those things",
      });
dest_dir=({KPATH+"room2","north",
	   KPATH+"room3","south",
	   "/players/exos/guard1","up",
         });
}
init(){
  ::init();
  AA("_up","climb");
  AA("_search","search");
}

_up(){
  MOVE("up#players/exos/guard1");
  return 1;
}
_search(){
  write("You search around, but find nothing.\n");
  say(TPN+" searches around for awhile.\n");
  return 1;
}
