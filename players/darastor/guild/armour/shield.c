
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/darastor/guild/barb.h"

reset(arg) {
    armour::reset(arg);
    if (!arg) {

	set_name("barbarian shield");
	set_alias("shield");
	set_type("shield");
    	set_ac(2);
	set_size(0);
	set_short("A barbarian shield");
	set_long("A dented and worn shield used in many battles.\n");
	set_value(400);
	set_weight(2);
  }
}

init () {
  ::init ();
  add_action("_wear","wear");
}

_wear(arg) {
	if (arg=="shield"){
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

