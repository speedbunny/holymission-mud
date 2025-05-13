inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"You step into the passage and quickly find that its slope is rather steep....\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"t54","south"});
if(!ob){
}
}
init(){
call_out("slide",0);
}
slide(){
write("You are sliding down a steep passage...\n");
write("");
write(" ");
write("This hurts alot....\n");
write(" ");
write(" ");
write("You fly out into sunlight and tumble down the side of the mountain.\n");
write(" ");
write(" ");
MOVE("down the passage#players/tatsuo/ishikawa/jungle/jung111");
return 1;
}
