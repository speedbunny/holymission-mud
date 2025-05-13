
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;

    	set_name("sword of Crom");
    	set_alias("sword");
    	set_class(20);
    	set_short("Sword of Crom");
    	set_long("This mighty bastard sword has taken countless lives and\n"+
      		 "has made cities fall to rubble. The sword is hammered \n" +
		 "and carved from the finest metals found across the lands. \n" +
		 "Guard this sword with your life. This is the finest \n" +
		 "barbarian weapon ever created.\n");
    	set_weight(8);
    	set_value(13000);
}

int query_barbarian_wield () {
    return 1;
}
