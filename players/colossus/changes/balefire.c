#include "lw.h"
#include "/players/colossus/guild/defines.h"
#include "/players/colossus/guild/lib/check_attack.h"
#include "/players/colossus/guild/lib/check_cost.h"

int do_balefire(string arg){
    object target;
    CG;
    if(check_cost(DEATH_COST, DEATH_LEVEL)){
	write("You're too mentally fatigued for that.\n");
	return 1;
    }
    if(!check_attack(arg)) {
	write("You cannot seen any such creature.\n");
	return 1;
    }
    target = check_attack(arg);
    write(lw("\n\
A cone of balefire leaps forth from your outstretched "+
	"hand, obliterating "+target->query_name()+"'s body.\n"));
    say(lw(
	"\n"+TP->query_name()+" points "+
	TP->query_possessive()+" hand towards "+
	target->query_name()+". Balefire springs forth from "+
	TP->query_name()+"'s palm, burning "+target->query_name()+
	"'s essence from the weave of Space and Time.\n"));
    target->hit_player(DAM(DEATH_DAM));
    TP->restore_spell_points(COST(-DEATH_COST));
    TP->add_exp(DAM(DEATH_DAM));
    return 1;
}
