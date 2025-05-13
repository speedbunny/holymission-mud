
inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;

	set_light(1);

	short_desc="Inner Courtyard";
	long_desc="You have entered a long courtyard. Plants, shrubs, and "+		"trees enhance the view. The school spends much time landscaping "+		"here. In the center is a squared section of open ground, surrounded"+
	" by the plant life. This is where the students practice their katas"+
	". The kata is a practiced and formalized routine in most martial "+
	"arts. The strength lies in it's repetition, repeating the sequences"+
	" until they are instinctive. \n";
	DD= ({ ZZ+"/dojo3", "west",
		ZZ+"/dojo6", "east" });
	clone_list = ({1, RAN(4), "student", MM+"/student", 0});
	::reset(arg);
	replace_program("room/room");
	}
