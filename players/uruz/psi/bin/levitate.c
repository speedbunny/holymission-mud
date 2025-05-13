#include "/players/trout/psi/psi.h"

#define LEV_LVL 14

main(string str){
object thing, shad;
int cost;

	
	if(!str){
	     write("Levitate what?\n");
	     return 1;
	     }
	thing= present(str, ENV(TP()));
	cost=(thing->query_weight()) * 8;
	if(!thing){
	    write("There is no "+CAP(str)+" here!\n");
	    return 1;
	    }
	if(check_level(LEV_LVL)){ return ;}
	if(check_cost(cost)){ return ;}
	if(check_armour()){ return 1;}
	if(thing->query_living()){
	    write("You can't levitate a living being!\n");
	    return 1;
	    }
	check_bleed();
	shad= CO(PSI+"/shadows/levitate_shad");
	shad->start_shadow(thing, 30, "levitate_shad");
	write("You use your mental powers to levitate the "+CAP(str)+".\n");
	TLR(ENV(TP()), "You watch in astonishment as the "+CAP(str)+" begins"+
	" to levitate up into the air!\n");
	TPRSP(-cost);
	return 1;
	}
