inherit "obj/monster";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("gathan");
	set_race("demon");
	set_aggressive(1);
	set_short("Gathan the Demon");
	set_long("This is Gathan, the great demon, that guards the prisoners of\n"+
	         "the fortress Haden. He has the body of a horse with three\n"+
	         "spiked tails and the head of a bear.\n");
	set_alias("gathan");
	set_level(50);
	set_al(-400);
	set_ac(14);
	set_wc(26);
    }
}

void init() {
    ::init();
    add_action("_north","north");
}
_north() {
    write("Gathan blocks your path\n");
    return 1;
}
