inherit "obj/armour";

reset (arg) {
    ::reset(arg);
    if(!arg) {
	set_name("vampire cape");
	set_short("vampire cape");
	set_alias("cape");
	set_ac(0);
	set_weight(0);
	set_value(50);
	set_long("The dark cape is spun from a thin and delicate material that is\n"+
	  "soft and velvety.\n");
	set_type("cloak");
    }
}

query_cape() { return 1; }  // needed for the quest
