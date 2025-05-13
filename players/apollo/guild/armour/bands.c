
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/apollo/guild/barb.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
	set_name("steel barbarian bands");
	set_alias("bands");
	set_type("arm");
	set_ac(1);
	set_size(0);
	set_short("Steel barbarian bands");
	set_long("Steel arm bands used to protect your arms and hands in combat.\n");
	set_value(200);
	set_weight(2);
    }
}

init(){
    ::init();
    add_action("_wear","wear");
}

_wear(arg){
    if(arg=="bands"){
	if(TP->query_guild()==11){
	    return 0;
	}
	else{
	    write("Only Barbarians may wear such armour.\n");
	    return 1;
	}
    }
    return 0;
}
