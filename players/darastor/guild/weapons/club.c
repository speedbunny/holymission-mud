
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg) {
 ::reset(arg);
 if (arg) return;
	set_name("barbarian club");
    	set_alias("club");
    	set_class(8);
    	set_short("Heavy set barbarian club");
    	set_long("The club is carved from a tree trunk. It looks like a good\n"+
    	         "weapon for bashing or even throwing.\n");
   	set_weight(3);
    	set_value(500);
}

int query_barbarian_wield () {
    return 1;
}
