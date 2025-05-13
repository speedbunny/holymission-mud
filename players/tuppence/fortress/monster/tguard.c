inherit "obj/monster";
#include "/players/tuppence/include/defs.h"
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("guard");
	set_race("troll");
	set_short("A troll guard");
	set_long("An ugly troll guard, guarding the gates.\n");
	set_alias("guard");
	set_level(17);
	set_al(-50);
	set_ac(8);
	set_wc(18);
money = clone_object("/obj/money.c");
money->set_money(400);
transfer(money,this_object());
    }
}

void init() {
    ::init();
    add_action("_north","north");
}
_north() {
    write("Troll guard says: you may not pass!\n");
    return 1;
}
