
inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Bamboo Studio";
	long_desc="This is the practice room where students learn weapon "+

	"combat. Most of the time they spar and practice their weapon katas"+
	". The walls are made of bamboo, and bear the marks of novice "+
	"students. \n";
	DD= ({ ZZ+"/dojo5", "west" });
	items= ({ "walls", "The bamboo has many gouges and slash marks" });
	clone_list = ({1, 3+RAN(5), "student", MM+"/student1", 0});
	::reset(arg);
	replace_program("room/room");
	}
