inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
    ::reset (arg);
    if(arg) return;
    set_name("halfling leader");
    set_alias("leader");
    set_level(16);
    set_wc(22);
    set_ac(7);
    set_al(0);
    set_gender(1);
    set_race("halfling");
    set_short("Leader");
    set_long("The halfling leader is siting in the chair with his blank\n"+
      "stare.  He seems to see everything and nothing in the same\n"+
      "moment.  He eems to radiate confidence and power.\n");
    add_money(200);
}

void init() {
    ::init();
    add_action("_press","press");
}

_press(str) {
    if(str=="eye") {
	write("The leader says: Get the hell away from my chair.\n");
	return 1;
    }

    if(!str) {
	write("What ?\n");
	return 1;
    }

    else {
	write("You wouldn't want to press that.\n");
	return 1;
    }
}

int attack() {
    object guard, attacker;

    attacker = this_object()->QA;
    guard = present( "halfling guard", environment( this_object() ) );
    if( !guard )
	return( ::attack() );
    say( "The guards will not allow you to attack their leader!\n" );
    this_object()->stop_fight();
    this_object()->stop_hunter();
    attacker->change_attacker( guard );
    return 0;
}
