
inherit "/obj/treasure";
#include "/players/trout/defs.h"

get(){ return 1;}
drop(string str){ return 1;}
id(str){ return str=="cease";}

reset(arg){
	::reset(arg);
	if(arg) return;
	set_weight(0);
	}

init(){
	::init();
	AA("_filter", "", 1);
	}

int _filter(string str){
	string verb;
	 
	verb= query_verb();
	if(verb[0]==39){
	    return 0;
	     }
	if(verb=="stop"){
	    write("You stop meditating.\n");
	    destruct(TO());
	    return 1;
	    }
	if(verb!="stop meditating"){
	    write("You must 'stop meditating' before you can do anything.\n");
	    return 1;
	    }
	else{ return 0;}
	return 0;
	}
