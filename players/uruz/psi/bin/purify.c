#include "/players/trout/psi/psi.h"
#define PURIFY_LVL 2
#define PURIFY_COST 40

int main(){
    string str;
	str=TPRN;
	if(check_level(PURIFY_LVL)){ return 1;}
	if(check_cost(PURIFY_COST)){ return 1;}
	if(check_block(str)){ return 1;}
	write("You sit down in a meditative trance, and begin to remove all "+
	"toxins from your body!\n");
	MO(CO("/players/trout/psi/obj/cease"), TP());
	call_out("remove", 15);
	TPRSP(-PURIFY_COST);
	return 1;
	}

int remove(){
	if(TP()->query_intoxination()<1 && TP()->query_poisoned()<1){
		write("You have cleared your body of all toxins.\n");
		return 1;
		}
	else{
	write("You feel more toxins being removed from your body!\n");
	TP()->add_poison(-10);
	call_other(TP(), "drink_alcohol", -10);
	return 1;
	}
    }
