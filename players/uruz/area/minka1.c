
inherit "room/room";
#include "/players/trout/defs.h"
int i, rnd;


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Minka";

	long_desc="You have entered a peasant minka. It is a large, single "+
	"room that has been divided into numerous sections by sliding paper "+
	"doors, and raised portions. It looks as if several families occupy "+
	"this minka. \n";

	DD= ({ ZZ+"/courtyd", "south" });
	items= ({ "door", "A sliding door made from a thin wooden frame, and "+

	"opague paper" });
	rnd=RAN(5);
	for(i=0; i<rnd; i++){
			MO( CO(YY+"/mobs/peasant"), TO() );
			}
	::reset(arg);
	replace_program("room/room");
	}

