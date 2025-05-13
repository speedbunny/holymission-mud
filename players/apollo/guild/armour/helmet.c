
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/apollo/guild/barb.h"

reset(arg) {
  armour::reset(arg);
  if (!arg) {
	
	set_name("bear helmet");
	set_alias("helmet");
	set_type("helmet");
	set_ac(2);
	set_size();
	set_short("A bear helmet");
	set_long("This tough helmet comes from a dead corpse of a bear.\n"+
		 "Its skull is used as the helmet but the teeth and fur \n" +
		 "are used as well for protection.\n");
	set_value(500);
	set_weight(3);
  }
}

init () {
  ::init ();
  add_action("_wear","wear");
}

_wear(arg) {
  if (arg=="helmet"){
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
