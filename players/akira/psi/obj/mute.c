
inherit "/obj/treasure";
#include "/players/akira/defs.h"

get(){ return 1;}
drop(string str){ return 1;}
id(str){ return str=="mute";}

reset(arg){
	::reset(arg);
	if(arg) return;
	set_weight(0);
	}

init(){
	::init();
	AA("_filter", "", 1);
	AA("_mute", "'");
	}

int _filter(string str){
	string verb;
	 
	verb= query_verb();
	if(verb[0]==39){
	    return 0;
	     }
	if(verb=="say"||verb=="'"||verb=="tell"||verb=="shout"||verb=="cast"){
	    write("You move your lips, but no sound comes out!\n");
	    return 1;
	    }
	else{ return 0;}
	return 0;
	}

int _mute(string str){
	write("You move your lips, but no sound comes out!\n");
	return 1;
	}
