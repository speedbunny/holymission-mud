inherit "/players/gareth/guild/obj/armour";
#include "/players/gareth/define.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("block-armour");
	set_type("guild");
	set_size(0);
	set_ac(0);
	}
drop(){return 1;}
short(){}
long(){}
init(){
	::init();
	AA("_lower", "lower");
	}
int _lower(string str){
	if(!str || str=="block"){
	  	write("You stop blocking!\n");
		destruct(TO);
		TP->restore_spell_points(-5);
		return 1;
		}
	}
