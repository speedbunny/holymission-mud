inherit "/obj/treasure";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg)return ;
	set_name("poisoner");
	set_short("poisoner");
	set_weight(0);
	}
get(){ return 1;}
drop(string str){ return 1;}
init(){
	::init();
	AA("_poison", "poison");
	}
int _poison(){
	TP()->add_poison(-50);
	return 1;
	}
