inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="On the coast of Ishikawa";
long_desc=break_string(
	"This is the northern most point of the island.  The shore is "+
	"peaceful and quiet, several small birds fly past seeking a "+
	"a meal.  A small path twists its way into the jungle to the "+
	"south.\n",65);


items = ({
	"island","The island of Ishikawa",
	"shore", long_desc,
	"birds","Seagulls perhaps",
	"path","It leads south",
	});
property=({
	});
dest_dir=({
	IPATH+"beach37","southeast",
	IPATH+"beach36","southwest",
	IPATH+"jung142","south",
	});
}
void init(){
::init();
}
