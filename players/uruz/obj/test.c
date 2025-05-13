inherit "obj/thing";
#include "/players/trout/defs.h"
reset(tick) {
	set_name("test object");
	set_can_get(1);
	set_weight(0);
	}
init(){
	::init();
	AA("_quit", "activate");
	}

int _quit(string str){
	if(str=="test"){
	command("say this works", this_player());
	return 1;
	}
     }
