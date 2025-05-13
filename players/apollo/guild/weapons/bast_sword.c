
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  
	set_name("bastard sword");
    	set_alias("sword");
    	set_class(12);
    	set_short("A barbarian bastard sword");
    	set_long("The sword is very heavy and looks exteremly rough\n"+
    	  	 "along the edges.\n");
    	set_weight(3);
    	set_value(1000);
}

int query_barbarian_wield () {
    return 1;
}
