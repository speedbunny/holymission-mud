inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
string slash;
reset(arg){
if(arg) return 1;
slash="machete";
set_light(1);
short_desc="In the Jungles of Ishikawa";
long_desc=break_string(
	"You are at the southern edge of a vast and dense jungle. "+
	"A small path heads south toward the dock, while to the north "+
	"the path virtually disappears into a tangle of plants and vines. "+
	"You would need a machete to go any further to the north.\n",65);


items = ({
	});
property=({
	});
dest_dir=({
	IPATH+"jung3","north",
	IPATH+"beach1","south",
	IPATH+"beach2","west",
	IPATH+"beach3","east",
	});
}
void init(){
::init();
AA("_north","north");
}
_north(){
if(present(slash,TP)){
MOVE("hacking "+TPOSS+" way north#players/tatsuo/ishikawa/jungle/jung3");
return 1;
}
else
write("You don't have anything that could cut through the foliage.\n");
return 1;
}
