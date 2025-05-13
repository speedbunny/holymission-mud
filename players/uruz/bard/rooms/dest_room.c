inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "A Hidden Room";
	long_desc= "You have entered a secret bard room. There are many rooms"+
	" like this one scattered throughout the lands. It's a place where "+
  	"bards can come to drop stuff, or recover from battle. There is a "+
	"an opening to a passage on the other side of the room. "+
	"A lone torch lights the room.\n";
	DD= ({ YY+"/workroom", "out",
		"room/church", "passage"
		});
	items= ({ "passage", "A long passage leads into the darkness. There "+
		  "is something written above the passage entrance",
		   "room", "A room hollowed out from rock",
		  "writing", "Why don't you try reading it"
		  });
	::reset(arg);
	}
init(){
	::init();
	AA("_read", "read");
	}
int _read(string arg){
	if(!arg){
		write("Read what?\n");
		return 1;
		}
	if(arg=="writing"){
		write("It reads 'Church'. You wonder what that means!\n");
		return 1;
		}
	}
