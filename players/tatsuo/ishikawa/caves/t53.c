inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"The walls of this passage are scorched black as midnight.  Claw "+
	"marks adorn the walls.  You sense the presence of a great "+
		"evil nearby.  The passage opens into a small cavern to the south. "+
	"To the north, and directly in front of you opens a HUGE archway into "+
	"the blackness beyond.  A pugnent smell of acrid poison wafts it way "+
	"into the room. Something does not seem right.\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"t54","north",
	   CPATH+"t52","south"});
hidden_dir=({CPATH+"truelair","down"});
property=({"no_teleport","no_sneak"});
if(!ob){
MO(CO(MAN+"pan-lung"),TO);
}
}
do_ser(){
write("A careful search indicates a hidden passage down.\n");
return 1;
}
init(){
  ::init();
  write("A draft blows through the room.\n");
}
