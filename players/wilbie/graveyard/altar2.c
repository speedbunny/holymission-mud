inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

void reset(int arg){
    clone_list=({
	 1,1,"idol","/players/wilbie/graveyard/monsters/idol",0,
	-1,6,"sword",WEAP+"idol_sword.c",0,
    });

    ::reset();
    if(arg) return;
    set_light(1);
    short_desc=
	"Before the idol";
    long_desc=
   	"You are in a small space behind the altar.  A large pedestal "+
   	"with a silver plaque on the front fills the area.  This part "+
   	"the cathedral looks like it has stood here for centuries.\n";
    items=({
	"pedestal",
	    "It is a large pedestal to hold a large idol",
	"plaque",
	    "It reads: The Dark Goddess",
	"area",
	    "A large space behind the altar",
	"space",
	    "It holds the Idol of the cathedral",
	"front",
	    "It holds a silver plaque",
	"cathedral",
	    "You are by the Idol of the cathedral",
	"silver",
	    "It is badly tarnished with age",
    });
    dest_dir=({
	GPATH+"altar1","south",
    });
}

void init() {
    ::init();
    add_action("read","read");
}

int read(string str) {
    if(str == "plaque") {
	write("It reads: The Dark Goddess.\n");
     	return 1;
    }
    notify_fail("What do you want to read?\n");
    return 0;
}
