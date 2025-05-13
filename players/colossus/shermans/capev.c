/* Edited by Colossus 022294 */

#pragma strict_types

inherit "obj/armour";

void reset(int arg){
    ::reset(arg);
    if(!arg) {
	set_name("vampire cape");
	set_alias("cape");
	set_ac(0);
	set_weight(0);
	set_value(50);
	set_short("Vampire cape");
	set_long(
	  "The dark cape has a coarse texture as it was spun from\n"+
	  "a thin and cheap material. It does nothing to enhance\n"+
	  "the appearance of the wearer.\n");
	set_type("cloak");
    }
}

