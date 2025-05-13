
inherit "/obj/treasure";
#include "/players/trout/defs.h"

get(){ return 1;}
drop(string str){ return 1;}
id(str){ return str=="headache";}

reset(arg){
	::reset(arg);
	if(arg) return;
	set_weight(0);
	}

init(){
	::init();
	call_out("dest", 90);
	AA("_stop", "mindbolt");
	AA("_stop", "purify");
	AA("_stop", "transmit");
	AA("_stop", "bio-regenerate");
	AA("_stop", "bio-manipulate");
	AA("_stop", "summon");
	AA("_stop", "levitate");
	AA("_stop", "mindbleed");
	AA("_stop", "mindblock");
	AA("_stop", "sense invisible");
	AA("_stop", "suggest");
	AA("_stop", "mindwipe");
	AA("_stop", "resist");
	AA("_stop", "neural");
	}

int _stop(string str){
	write("You can't seem to concentrate enough to use your powers with "+
	"this painful headache!\n");
	return 1;
	}

dest(){
	write("Your headache seems to subside!\n");
	destruct(TO());
	return 1;
	}
