// 061197: Sauron: Added check to make sure that the armour is in the player's
//                 inventory.

#include "/players/gareth/define.h"
INHERIT

reset(arg) {
    ::reset(arg);
    if(arg) return;
   set_name("Lost Armour of Achilles");
    set_type("armour");
    set_alias("armour");
    set_size(3);
    set_short("The lost Armour of Achilles");
    set_long("This great suit of full plate armour was worn by the great\n"+
             "fighter Achilles; the greatest hero of the Greeks. It's \n"+
	     "stronger than a castle wall and lighter than a bird's feather\n"+
	     "It glows with a magical radiance that far surpasses the\n"+
	     "brightness of the sun. This Armour could have only come from\n"+
	     "the Gods of Olympus.\n\n");
    set_ac(4);
    set_weight(2);
    set_value(10000);
    set_light(1);
    modify_stat(1,3);
}

wear(arg) {
    if(environment(this_object()) != TP) return ::wear(arg);
    if(TP->query_npc()) return ::wear(arg);
    if(TP->query_real_guild() !=3) {
	write("The Lord of Olympus had meant it for someone else. \n");
	return 1;
    }
    return ::wear(arg);
}
