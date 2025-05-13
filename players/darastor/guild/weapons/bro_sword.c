
/* Gambit - Barbarian Guild */

inherit"obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;
 
   	set_name("broad sword");
   	set_alias("sword");
    	set_class(11);
    	set_short("A barbarian broad sword");
    	set_long("The sword looks very rough but is crafted in a strange\n"+
      		 "way. Many knicks and grooves run along the edges.\n");
    	set_weight(3);
    	set_value(1000);
}

int query_barbarian_wield () {
    return 1;
}
