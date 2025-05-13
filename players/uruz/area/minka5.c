
inherit "room/room";
#include "/players/trout/defs.h"
int i;


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Minka";

	long_desc="You have entered a peasant minka. It is a large, single "+
	"room that has been divided into numerous sections by sliding paper "+
	"doors, and raised portions. It looks as if several families occupy "+
	"this minka. \n";
	DD= ({ ZZ+"/courtyd", "north" });
	items= ({ "door", "A sliding door made from a thin wooden frame and "+
	"opague paper" });
	for(i=0; i<RAN(5); i++){
				MO( CO(MM+"/peasant"), TO() );
				}

	::reset(arg);
	replace_program("room/room");
	}
