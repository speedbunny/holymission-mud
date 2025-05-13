inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"
int i,x;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Guards Quarters";
	long_desc="You are now in a guards quarters at Honno Ji. This room "+

	" is filled with bunk beds, lined in rows neatly. Racks of armour "+
	"and weapons fill the walls. It looks as if more than 100 men could "+
	"be housed here! \n";
	DD= ({ ZZ+"/daimyo", "north",
		ZZ+"/gallery", "west" });
	items= ({ "beds", "Your basic bunk bed" });
	x=3+RAN(5);
	for(i=0; i<x; i++){
		switch(RAN(10)){
				case 0..6: MO(CO(MM+"/guard1"), TO());
					   break;
				case 7..9: MO(CO(MM+"/guard2"), TO());
					   break;
				}
			}
	::reset(arg);
	replace_program("room/room");
	}
