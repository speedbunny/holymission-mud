inherit "spells/spell";
#include "/spells/spell.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("Cloak");
    set_syntax("cast 'cloak'");
    set_kind( NO_COMBAT );
    set_player_help("The cloak of Space and Time has literally been sewn from the fabric\n\
of Space and Time. This cloak has the ability to contain things\n\
and it offers very good protection along with that.\n");
    set_guild_allowed(10,1);
    set_cost(4);
    set_speed( INSTANT );
}

void release(string arg, int act_skill, int max_skill ){
    object cloak;
    if ( check_success( act_skill, max_skill ) ) {
	if(present("rainbow cloak", TP) ){
	    write("You already have one.\n");
	    return;
	}
	cloak = clone_object("/players/colossus/guild/lib/armcontain");
	if(transfer(cloak, TP)){
	    write("You are carrying too much.\n");
	    return;
	}
	command("wear cloak", TP);
    }
}
