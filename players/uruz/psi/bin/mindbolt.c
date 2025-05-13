#include "/players/trout/psi/psi.h"
#define BOLT_LVL 1
#define BOLT_COST 45

main(string str){
int BOLT_DMG;

object who;

	if(!str){
	    write("Mindbolt who?\n");
	    return 1;
	}
	who=present(str, ENV(TP()));
	if(!who){
		write(CAP(str)+" is not here!\n");
		return 1;
		}
	if(who->query_immortal()){
		if(!TP()->query_immortal()){
			write("It would not be wise to attack an immortal!\n");
			return 1;
			}
		}
	if(check_level(BOLT_LVL)){ return 1;}
	if(check_cost(BOLT_COST)){ return 1;}
	if(check_armour()){ return 1;}
	if(check_block(str)){ return 1;}
	check_bleed();
	BOLT_DMG= (TP()->query_int()*3)+(TPQL*2);
	if(BOLT_DMG > 110){ BOLT_DMG= 110;}
	write("You hit "+str+" with a devistating mindbolt!\n");
	TELL(who, CAP(TPRN)+" hits you with a devistating mindbolt!\n");
	who->hit_player(BOLT_DMG, 7);
	TPRSP(-BOLT_COST);
	return 1;
	}
