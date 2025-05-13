inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"The cavern is engulfed in darkness.  Half-eaten mukade and shikome "+
	"corpses are strewn about the passage.  The stench of death hangs "+
	"heavy about your soul.  Do you dare continue?  A small slope "+
	"leads up to a hole in the ceiling, while north lies only "+
	"oblivion.\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"c20","up",CPATH+"t51","north"});
property=({"no_teleport","no_sneak"});
if(!ob){
MO(CO(ISHOB+"cskeleton"),TO);
}
}
