
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;

    	set_name("jaw of a jack-ass");
    	set_alias("jaw");
    	set_class(16);
    	set_short("A jaw of a jack-ass");
    	set_long("This used to be the jaw of a live jack-ass but over time\n"+
      		 "after the animal died, the bones got hard and the jaw harden with\n"+
      		 "strength. A great barbarian weapon.\n");
    	set_weight(16);
    	set_value(3000);
}

int query_barbarian_wield () {
    return 1;
}
