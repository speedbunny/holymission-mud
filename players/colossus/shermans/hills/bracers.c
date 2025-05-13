/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "obj/armour";

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("bracers");
	set_type("arm/armour");
	set_ac(2);
	set_weight(1);
	set_value(10000);
	set_short("Demon bracers");
	set_long("The bracers are made of the tough and horny hide\n"+
	  "of some unfortunate beast. They emit a\n"+
	  "blackness that only hints at the dark\n"+
	  "magic that must have created it.\n");
    }
}

status query_mage_wear(){
    return 1;
}
status query_monk_wear(){
    return 1;
}

