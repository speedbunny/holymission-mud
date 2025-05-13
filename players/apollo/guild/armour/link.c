
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#define TP this_player()

reset(arg) {
  armour::reset(arg);
  if (!arg) {

	set_name("Barbarian chain link");
	set_alias("link");
	set_type("armour");
	set_ac(4);
	set_size(0);
	set_short("Barbarian link armour");
	set_long("This armour is made from small links of metal combined\n"+
		 "with bear fur. Very dependable but not as strong as splint \n" +
		 "mail.\n");
	set_value(1000);
	set_weight(3);
  }
}

init (){
  ::init ();
  add_action("_wear","wear");
}

_wear(arg) {
	if (arg=="link"){
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

