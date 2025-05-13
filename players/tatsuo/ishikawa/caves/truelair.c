inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;
reset(arg){
if(arg) return;
set_light(-5);
short_desc="Lair of Kyoshi";
long_desc=break_string(
	"Kyoshi has cleverly hidden himself here, in this small cave.  "+
	"The only exit is up.\n",65);
items=({"cavern",long_desc,
	"corpses","They look like dinner for something very large",
	"slope","It leads up, maybe a good idea at this point",
	"oblivion","AHHHHH, you get scared and stop looking at it",
      });
dest_dir=({CPATH+"t53","up"});
property=({"no_teleport","no_sneak"});
if(!ob){
MO(CO(MAN+"serpentking"),TO);
}
}
init(){
::init();
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
