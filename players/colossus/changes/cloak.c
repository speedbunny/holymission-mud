#include "/players/colossus/guild/defines.h"
#include "/players/colossus/guild/lib/check_cost.h"

int do_cloak(){
    object cloak;
    CG;
    if(present("rainbow cloak", TP) ){
	write("You already have one.\n");
	return 1;
    }
    if(check_cost( CLOAK_COST, CLOAK_LEVEL) )
	return 1;
    cloak = clone_object("/players/colossus/guild/lib/armcontain");
    if(transfer(cloak, TP)){
	write("You are carrying too much.\n");
	return 1;
    }
    transfer(cloak, TP);
    command("wear cloak", TP);
    TP->restore_spell_points(COST(-CLOAK_COST));
    return 1;
}
