
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;
    	
	set_name("barbarian war hammer");
    	set_alias("hammer");
    	set_class(12);
    	set_short("A barbarian war hammer");
    	set_long("The war hammer is a huge hammer that looks like it can\n"+
      		 "smash anything in sight. Only the strong can wield this \n" +
		 "weapon.\n");
    	set_weight(4);
    	set_value(2900);
}

int query_barbarian_wield () {
    return 1;
}
