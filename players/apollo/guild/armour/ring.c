
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/apollo/guild/barb.h"

reset(arg) {
  armour::reset(arg);
  if (!arg) {

	set_name("barbarian ring mail");
	set_alias("mail");
	set_type("armour");
	set_ac(3);
	set_size(0);
	set_short("Barbarian ring mail");
	set_long("The armour is made out of old pieces of leather and rings\n"+
	  	 "and large straps of metal.\n");
	set_value(375);
	set_weight(3);
    }
}

init (){
    ::init ();
    add_action("_wear","wear");
}

_wear(arg) {
    if (arg=="mail"){
	if(TP->query_guild()==11) {
	    return 0;
	}
	else {
	    write("Only Barbarians may wear such armour.\n");
	    return 1;
	}
    }
    return 0;
}

