
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg) {
 ::reset(arg);
 if (arg) return;
   
	set_name("battle axe");
    	set_alias("axe");
    	set_class(14);
    	set_short("A barbarian battle axe");
    	set_long("This battle axe looks very strong and powerful.\n"+
      		 "It was made by the harsh craftsmenship of some barbarians.\n");
    	set_weight(4);
    	set_value(2500);
}

int query_barbarian_wield () {
    return 1;
}
