inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"

object kbl;

reset(arg){
 if(arg) return;
if(!kbl || !living(kbl)){
MO(CO(MON+"kobold"),TO);
}
short_desc="Dungeon of Hilo";
long_desc=break_string(
	"You are in a rock hewn corridor leading north and south.  The "+
	"sound of trickling water is the only noise here.  A draft blows "+
	"from the north.  You can make out more of the small clawed footprints "+
	"heading in all directions.\n",65);
items=({"corridor", long_desc,
	"water","You can hear it not see it",
	"footprints","They lead in many directions",
	"directions","You know, north, south, east, those things",
	});
smell= "It smells like wet dog down here";
dest_dir=({KPATH+"room1","north",
	   KPATH+"room4", "south",
	});
}
init(){
  ::init();
  AA("_search","search");
}
_search(){
write("You search around for a while.\n");
say(TPN+" searches around for a while.\n");
return 1;
}
