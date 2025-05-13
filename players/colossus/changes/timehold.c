#include "lw.h"
#include "/players/colossus/guild/defines.h"
#include "/players/colossus/guild/lib/check_attack.h"
#include "/players/colossus/guild/lib/check_cost.h"

int do_timehold(string arg){
    object target;
    CG;
    if(check_cost(TIME_COST, TIME_LEVEL)){
	write("You're too mentally fatigued for that.\n");
	return 1;
    }
    if(!check_attack(arg)){
	write("There is no such creature here.\n");
	return 1;
    }
    target = check_attack(arg);
    write(lw("\n\
You Create a rift in Space and Time which engulfs "+
	target->query_name()+" and renders "+
	target->query_objective()+" powerless while screaming in pain.\n"));
    say(lw(
	TP->query_name()+" creates a rift in Space and Time which engulfs "+
	target->query_name()+" and renders it harmless and screaming in "+
	"pain.\n"));
    if(target->query_player()){
	target->hold(TP, TIME_DUR/3);
	target->hit_player(DAM(TIME_DAM));
	TP->attacked_by(target);
	TP->restore_spell_points(COST(-TIME_COST));
	TP->add_exp(DAM(TIME_DAM));
	return 1;
    }
    target->hold(TP, TIME_DUR);
    target->hit_player(TIME_DAM);
    TP->attacked_by(target);
    TP->restore_spell_points(-TIME_COST);
    TP->add_exp(TIME_DAM);
    return 1;
}
