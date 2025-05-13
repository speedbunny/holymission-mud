
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Ane Riverbank";
	long_desc= "You are stand on the northern bank of the Ane River. You "+
	"can see many large rocks in the water. The wreckage of a fishing "+		"boat occupies one of the rocks in the center.\n";
	DD= ({ ZZ+"/fief2", "northwest",
		ZZ+"/fief6", "east"});
	items= ({ "river", "The deep, dark river Ane",
		"rocks", "Water rapids surround the many protruding rocks",
		"wreckage", "It looks like an old pirate ship",
		"boat", "It looks like an old pirate ship",
		"rock", "A group of rocks protrude from the water"});
	MO(CO(YY+"/obj/sign1"), TO());
	}
	init() {
	::init();
	AA("_dive", "dive"); }
	_dive(str){
		if(!str||str=="down"||str=="river"){
			this_player()->hit_player(80, 7);
			write("You hit the rocks. OUCH! \n");
			this_player()->move_player("down#players/trout/area/"+
			"river7");
			return 1; }
		}
