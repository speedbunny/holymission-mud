#include "/players/trout/psi/psi.h"

#define WIPE_LVL 24
#define WIPE_COST 200

main( string str){
   object target, shad;
	if(check_level(WIPE_LVL)){ return 1;}
	if(check_cost(WIPE_COST)){ return 1;}
	if(check_block(str)){ return 1;}
	check_bleed();
	if(!str){
	    write("Mindwipe who?\n");
	    return 1;
	    }
	target= present(str, ENV(TP()));
	if(!target){
	    write(CAP(str)+" is not here!\n");
	    return 1;
	    }
	shad=CO(PSI+"/shadows/wipe_shad");
	shad->start_shadow(TP(), 120, "wipe_shad");
	write("You enter into "+CAP(str)+"'s mind, and erase part of his "+
	"memory temporarily!\n");
	TELL(target, "You seem to forget how to use your weapons!\n");
	TPRSP(-WIPE_COST);
	return 1;
	}
