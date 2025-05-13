#include "/players/trout/psi/psi.h"
#define STRIKE_LVL 28
#define STRIKE_COST 275

main(string str){

string target;
object who;

	if(!str){
	    write("Useage: neural strike <opponent> \n");
	    return 1;
	    }
	sscanf(str, "strike %s", target);
	if(!target){
	    write("Neural strike who?\n");
	    return 1;
	    }
	who=present(target, ENV(TP()));
	if(!who){
		write(CAP(target)+" is not here!\n");
		return 1;
		}
	if(who->query_immortal()){
		if(!TP()->query_immortal()){
			write("It would not be wise to attack an immortal!\n");
			return 1;
			}
		}
	if(check_level(STRIKE_LVL)){ return 1;}
	if(check_cost(STRIKE_COST)){ return 1;}
	if(check_block(str)){ return 1;}
	check_bleed();
	write("You focus your powers and destroy "+CAP(target)+" with a "+
	"percise attack on "+who->query_possessive()+" neural system!\n");
	TELL(who, CAP(TPRN)+" destroys you with a awesome neural strike!\n");
	who->hit_player(400, 4);
	TPRSP(-STRIKE_COST);
	return 1;
	}
