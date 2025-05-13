#include "/players/sargon/define.h"
INHERIT

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("artemis' platemail");
    set_type("armour");
    set_alias("platemail");
    set_size(3);
    set_short("Artemis' Platemail");
    set_long("This suit of platemail was once worn by Artemis, the\n"+
             "female Goddess of archery. Its weight is equal to that\n"+
	     "of leather and stronger than iron. You feel that it\n"+
	     "emits a small amount of magical energy.\n\n");
    set_ac(3);
    set_weight(1);
    set_value(15000);
    modify_stat(1,1);
    modify_stat(0,1);
}

wear(arg) {
    if(TP->query_npc()) return ::wear(arg);
    if(TP->query_gender() !=2) {
	write("You may bitch like a woman, but yer NO lady! \n");
	return 1;
    }
    return ::wear(arg);
}
