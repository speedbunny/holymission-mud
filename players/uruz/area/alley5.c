inherit "room/room";
#include "/players/trout/defs.h"
int i;
object corpse;

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc= "A Bloody Alley";
	long_desc= "You now stand in the middle of a virtual blood-bath. "+
	"Bodies lie scattered along the ground. Two gangs appear to be "+
	"fighting here. One group is dressed in white, and wear gold "+
	"headbands. The other group is dressed in black, with red sashes. "+
	"Casualties appear moderately on both sides. Maybe it's time to "+
	"leave? \n";
	DD= ({ ZZ+"/alley6", "north",
		ZZ+"/alley4", "west" });
	items= ({ "gangs", "The group in white are the Fighting Tong. They"+
		"'re the good guys. The group in black are the Wang-Cyng. "+
		"they're the bad guys!" });
	for(i=0; i<2+RAN(6); i++){
		MO(CO(MM+"/wyng"), TO()); }
	for(i=0; i<2+RAN(6); i++){
		MO(CO(MM+"/tong"), TO());
		}
	for(i=0; i<3+RAN(4); i++){
		MO(CO(YY+"/obj/corpse"), TO()); }
	::reset(arg);
	replace_program("room/room");
	}
