#include "/players/akira/psi/psi.h"

#define INNER_LVL 15
#define INNER_COST 50

main( string str){
   object shad;
	if(check_level(INNER_LVL)){ return 1;}
	if(check_cost(INNER_COST)){ return 1;}
	if(check_block(TPRN)){ return 1;}
	check_bleed();
	if(!str){
	    write("Useage: summon inner strength.\n");
	    return 1;
	    }
	if(str=="inner strength"){
	    shad=CO(PSI+"/shadows/inner_shad");
	    shad->start_shadow(TP(), 25, "inner_shad");
	    write("You summon all your inner strength!\n");
	    TPRSP(-INNER_COST);
	    }
	return 1;
	}
