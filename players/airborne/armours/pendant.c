
inherit "obj/armour";

reset(arg){
 ::reset(arg);
 if(arg) return;

	set_name("pendant");
	set_type("amulet");
	set_weight(0);
	set_ac(1);
	set_short("A beautiful pendant");
	set_long("A beautiful pendant.\n");
   return 1;
	}
