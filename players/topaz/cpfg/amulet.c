inherit "obj/armour";
#include "/players/gambit/defs2.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_id("amulet");
    set_alias("ninjas amulet");
    set_short("A amulet of Amaterasu");
    set_long(BS("This is the ancient amulet of Amaterasu.  It is rumored "+
	"to protect the follow of Amaterasu wearing the amulet."));
    set_type("amulet");
    set_arm_light(1);
    set_ac(1);
    set_size(0);
    set_value(300);
    set_weight(1);
}
query_ninja_wear() { return 1; }
int wear(string arg)
{
    if (this_player()->query_religion()!= "Amaterasu") {
	write(BS("Sorry, but you are not a follower of Amaterasu."));
	return 1;
    }
    return::wear(arg);
}
