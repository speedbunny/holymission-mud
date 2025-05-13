inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"

object kbl;
reset(arg){
 if(arg) return;
 set_light(0);
 short_desc="Dungeon of Hilo";
 long_desc=break_string(
	"The corridor branches here heading north, south, and east. "+
	"The rock hewn corridor seems to be getting smaller to the south. "+
	"There are some deep gashes in the ceiling.\n",65);
items=({"corridor",long_desc,
	"gashes","It looks like someone was trying to break through to the surface",
	});
dest_dir=({KPATH+"room4","north",
	   KPATH+"room8","east",
	   KPATH+"room11","south",
});
smell="It smells like wet dog down here";
}
init(){
  ::init();
  AA("_south","south");
}
_south(){
  if(TP->query_size()<3){
   MOVE("south#players/unuscione/area/room11");
    return 1;
   }
  else {
   write("You are much too big to go further south.\n");
   return 1;
}
}
