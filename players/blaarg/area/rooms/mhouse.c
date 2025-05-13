#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"moose",MOB+"moose",0,
		-1,1,"clawkey","/players/blaarg/stuff/quest_stuff/key",0,
	});
	set_light(1);
	short_desc="Moose's House",
	long_desc=
		"Moose's house is quite small, compared to the Tendo Dojo,\n"+
		"but it is still quite beautiful. On the floor is a mat,\n"+
		"and in the room are a bed, a dresser, a window, and a chair.\n";
	dest_dir=({
		AROOMS+"roadb3","north",
		 });
	items=({
	    "window","You can see the road from here, and across the road"+
		     "is the Tendo Dojo",
	    "chair","The bamboo chair looks very comfortable",
	    "mat","The mat has some calligraphy on it",
	    "dresser","The dresser is made of beautiful hardwood, but you"+
		      "cannot open it. There is a picture on it",
	    "picture","A class photo, with all the crew in it", 
       });
	smell = "The entry smells of Sandalwood";
	::reset(arg);
	if(arg) return;
}

init()
{
  ::init();
  add_action("unlock","unlock");
}

unlock(str){
	if(str="dresser") {
	  write("You cannot unlock the dresser!\n");
	  return 1;
	}
	write("Unlock What?\n");
	return 1;
}

