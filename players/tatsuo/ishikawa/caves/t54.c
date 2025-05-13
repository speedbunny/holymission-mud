inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"The lair of Kyoshi shines bright before your eyes.  The gleam "+
	"of a thousand jewels embedded in the walls is almost quite "+
	"astounding.  A rather large passage leads north.  "+
	"IT APPEARS THAT KYOSHI HAS DECEIVED YOU, A RIVER OF "+
	"POISON POURS IN FROM ABOVE.\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"t53","south",CPATH+"t55","north"});
property=({"no_teleport","no_sneak"});
if(!ob){
}
}
init(){
::init();
this_player()->add_poison(random(this_player()->query_maxhp()/3));
write("You feel Very Ill. Better seek treatment.\n");
AA("_north","north");
}
_north(){
if(present("kyoshi", this_object())){
write("Kyoshi blocks your path!\n");
return 1;
}
else{
return 0;
}
}
