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
	"You stand at the northren edge of a vast and dense jungle. "+
	"A small path leads south through the jungle, while to the north "+
	"you can see the coast through a tangle of plants and vines. "+
	"\n",65);


items = ({
	});
property=({
	});
dest_dir=({
	IPATH+"beach38","north",
	IPATH+"beach37","east",
	IPATH+"beach36","west",
	IPATH+"jung140","south",
	});
}
void init(){
::init();
}
_south(){
if(present(slash,TP)){
MOVE("hacking "+TPOSS+" way south#players/tatsuo/ishikawa/jungle/jung140");
return 1;
}
else
write("You don't have anything that could cut through the foliage.\n");
return 1;
}
