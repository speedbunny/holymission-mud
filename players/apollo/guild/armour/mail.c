
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/apollo/guild/barb.h"

reset(arg) {
 armour::reset(arg);
 if (!arg) {

	set_name("barbarian splint mail");
	set_alias("mail");
	set_type("armour");
	set_ac(4);
	set_size(0);
	set_short("Barbarian splint mail");
	set_long("This armour is much stronger and more used by the Barbarians\n"+
		 "because of its lasting power and strength. The armour is made\n"+
		 "from single strips of metal with stitches of fear and hide \n" +
		 "laced in between.\n");
	set_value(2000);
        set_weight(5);
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

