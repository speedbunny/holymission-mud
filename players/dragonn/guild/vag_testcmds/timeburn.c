#include "/players/nylakoorub/guild/defines.h"
#include "/obj/lw.h"

int do_timeburn(string arg) {
    object target;
    CG;
    if(check_cost(TIMEBURN_COST, TIMEBURN_LEVEL)) {
	write("You're too mentally fatigued for that.\n");
	return 1;
    }
    if(!check_attack(arg)) {
	write("You cannot seen any such creature.\n");
	return 1;
    }
    target = check_attack(arg);
    if(environment(this_player())->query_property("no_fight")){
	write("You cannot do this as this sanctuary.\n");
	return 1;
    }
    write(lw("\n\
A cone of fire leaps forth from your outstretched "+
	"hand, obliterating "+target->query_name()+"'s body.\n"));
    say(lw(
	"\n"+TP->query_name()+" points "+
	TP->query_possessive()+" hand towards "+
	target->query_name()+". A cone of fire spring forth from "+
	TP->query_name()+"'s palm, burning "+target->query_name()+
	"'s essence from the weave of Space and Time.\n"));
    target->hit_player(DAM(TIMEBURN_DAM),5);
    return 1;
}
