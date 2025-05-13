#include "/players/gareth/define.h"
INHERIT

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Lost shield of Achilles");
    set_type("shield");
    set_alias("shield");
    set_size(3);
    set_short("The lost Shield of Achilles");
    set_long("A great shield once used by the great fighter Achilles; The\n"+
      "greatest hero of the greeks. It's glows with a great radiance\n"+
      "that equals the brightness of the sun. It's strength could have\n"+
      "only come from the power of the Gods. \n");
    set_ac(4);
    set_weight(2);
    set_value(10000);
    set_light(1);
    modify_stat(1,2);

}

wear(arg) {
    if(TP->query_npc()) return ::wear(arg);
    if(TP->query_real_guild() !=3) {
	write("The Lord of Olympus had meant it for someone else. \n");
	return 1;
    }
    return ::wear(arg);
}
