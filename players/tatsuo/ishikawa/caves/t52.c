inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"This passage opens into another lair.  You have heard from "+
	"legend that this is the home of T'ien-Lung, the Celestial "+
	"dragon.  The lair is simple for such a powerful creature.\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"lair","It is a simple cavern",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"t53","north",CPATH+"t51","south"});
property=({"no_teleport","no_sneak"});
if(!ob){
MO(CO(MAN+"t'ien-lang"),TO);
}
}
