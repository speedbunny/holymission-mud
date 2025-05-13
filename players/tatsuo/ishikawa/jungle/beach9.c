inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob1;
reset(arg){
if(arg) return 1;
::reset(arg);
set_light(1);
short_desc="On the coast of Ishikawa";
long_desc=break_string(
	"You are on the eastern coast of Ishikawa. A vast sea streches "+
	"to the eastren horizon.  A path leads into "+
	"jungle to the west. The tide washes over the black sand of the "+
	"beach.  "+
	"The coast continues to the northeast and southwest.\n",65);


items = ({
	"coast",short_desc,
	"sea","Wow, lots of water",
	"horizon","The horizon glows red with the setting sun",
	"path","A small path leading west",
	"jungle","its very dense and dark",
	"tide","It flows and ebbs over the black basaltic sand. You get dizzy",
	"sand","It is black, derived from a basaltic granite",
	});
      ob1=CO("players/tatsuo/ishikawa/monsters/gull");
      MO(ob1,this_object());
property=({
	});
dest_dir=({
	IPATH+"beach7","southwest",
	IPATH+"beach11","northeast",
	IPATH+"jung16","west",
	});
}
void init(){
::init();
AA("_search","search");
AA("_swim","swim");
}
_search(){
write("You search around for a while and find nothing.\n");
say(TPN+" searches around.\n");
return 1;
}
_swim(){
write("You jump in the ocean and swim around awhile.\n");
say(TPN+ " jumps in the ocean and swims around awhile.\n");
return 1;
}
