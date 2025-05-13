
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/darastor/guild/barb.h"

reset(arg) {
  armour::reset(arg);
  if (!arg) {

	set_name("chain and fur");
	set_alias("fur");
	set_type("armour");
	set_ac(2);
	set_size(0);
	set_short("Barbarian chain and fur");
	set_long("A simple weave of old chains and metal pieces wrapped in fur.\n");
	set_value(300);
	set_weight(2);
  }
}

init () {
  ::init ();
  add_action("_wear","wear");
}

_wear(arg) {
	if (arg=="fur"){
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

