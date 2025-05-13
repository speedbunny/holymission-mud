#pragma strict_types

inherit "obj/armour";

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("demonplate");
	set_alias("plate");
	set_type("armour/legs");
	set_ac(6);
	set_weight(7);
	set_value(10000);
	set_short("Demonplate");
	set_long("A red plate mail with flame symbols.\n");
    }
}

