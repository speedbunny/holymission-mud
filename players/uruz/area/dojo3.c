
inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Padded Studio";
	long_desc= "You have entered a large, open studio. The whole floor "+
	"and halfway up the walls are padded. This is where the bulk of a "+

	"student's time is spent practicing hand to hand combat. Windows "+
	 "line the upper portion of the room. \n";
	DD= ({ ZZ+"/dojo1", "north",

		ZZ+"/dojo5", "east" });

	items= ({ "windows", "Large windows made of glass, often used to "+			"let in light",
		"floor", "The padded floor goes 'squish' as you step on it" });
	clone_list = ({1, 3+RAN(5), "student", MM+"/student", 0});
	::reset(arg);
	replace_program("room/room");
	}
