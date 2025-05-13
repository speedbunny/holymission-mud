inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
object kbl;

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc="Dungeon of Hilo";
  long_desc=break_string(
	"Rubble and debris cover the floor here.  It appears that "+
	"the Kobolds have been trying to break through to the surface "+
	"here.  The corridor continues east and west.  The ceiling "+
	"looks unstable.\n",65);
smell="It smells like wet dog down here";
items=({"rubble","A pile of rock chipped away from the ceiling",
	"debris","A pile of rock chipped away from the ceiling",
	"surface","You are on the wrong side to see that",
	"ceiling","Don't make any loud noises here",
	});
dest_dir=({KPATH+"room7","west",
	   KPATH+"room9","east",
	});
if(!kbl || !living(kbl)){
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
MO(CO(MON+"kguard"),TO);
}
}
init(){
  ::init();
  AA("noise","shout");
AA("noise","scream");
}
noise(){
  write("The loud noise causes the ceiling to collapse.\n");
  say(TPN+"'s shout caused the ceilng to collapse.\n");
  TP->hit_player(15);
  write("You are hurt by falling debris.\n");
  say("You manage to avoid the falling debris.\n");
  return 1;
}
