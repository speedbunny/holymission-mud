inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"The passage opens into a large chamber. This appears to be the "+
	"lair of several dragons.  The high arched ceiling disappears "+
	"into darkness.  Passages lead off to the north and south.\n",65);
items=({"cavern",long_desc,
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
	"lair","The serpents make their home in here",
      });
dest_dir=({CPATH+"t52","north",CPATH+"t50","south"});
property=({"no_teleport","no_sneak"});
if(!ob){
MO(CO(MAN+"serpent"),TO);
MO(CO(MAN+"serpent"),TO);
MO(CO(MAN+"serpent"),TO);
MO(CO(MAN+"serpent"),TO);
}
}
