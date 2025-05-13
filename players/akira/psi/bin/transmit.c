#include "/players/akira/psi/psi.h"

#define FEAR_LVL 6
#define DESPAIR_LVL 23
#define HATE_LVL 18
#define CALM_LVL 12
#define COURAGE_LVL 13
#define FCC_COST 25
#define DESPAIR_COST 50
#define HATE_COST 75

main (string str){
   object target, shad;
   string type, who;
	if(!str){
	    write("What kind of emotion do you want to transmit?\n");
	    return 1;
	    }
	if(str=="calm"){
	    call_out("calm", 0);
	     return 1;
	    }
	sscanf(str, "%s at %s", type, who);
	if(!who){
		write("Useage: transmit <type> at <who>\n");
		return 1;
		}
	target=present(who, ENV(TP()));
	if(!target){
	    write(CAP(who)+" is not there!\n");
	    return 1;
	    }
	if(target->query_immortal() && !TP()->query_immortal()){
	    write("You don't have the skills to transmit any emotion "+
	    "to an immortal!\n");
	    return 1;
	    }
	if(check_block(TPRN)){ return 1;}
	check_bleed();
	if(type=="fear"){
	    if(check_level(FEAR_LVL)){ return 1;}
	    if(check_cost(FCC_COST)){ return 1;}
	    write("You transmit fear into "+who+", causing "+
	    " "+query_poss(target)+" to turn pale white and run!\n");
	    TELL(target, "You are overwhelmed by a feeling of fear "+
	    "and deciide to leave the area!\n");
	     target->run_away();
	    TPRSP(-FCC_COST);
	    return 1;
	     }
	if(type=="courage"){
	    if(check_level(COURAGE_LVL)){ return 1;}
	    if(check_cost(FCC_COST)){ return 1;}
	    if(target->query_wimpy()==0){
		write(CAP(who)+" has more than enough courage already.\n");
		return 1;
	   	}
	    target->set_wimpy(0);
	    write("You transmit courage into "+who+"'s mind.\n");
	    TELL(target, "You are filled with a feeling of raw courage. "+
	    "Your ready to take on anything.\n");
	    TPRSP(-FCC_COST);
	    return 1;
	    }
	if(type=="hate"){
	     if(check_level(HATE_LVL)){ return 1;}
	     if(check_cost(HATE_COST)){ return 1;}
	     shad= CO(PSI+"/shadows/hate_shad");
	     shad->start_shadow(TP(), 10, "hate_shad");
	     if(TPRN == who){
		write("You fill yourself with hatred. You are now in a rage"+
		"!\n");
		return 1;
		}
	     else{ 
		TELL(target, "You are overwhelmed with hatred. You feel the "+
		"need to go break something, or somebody!\n");
		return 1;
		}
	     TPRSP(-HATE_COST);
	     }
	     if(type=="despair"){
		if(check_level(DESPAIR_LVL)){ return 1;}
		if(check_cost(DESPAIR_COST)){ return 1;}
		shad= CO(PSI+"/shadows/despair_shad");
		shad->start_shadow(TP(), 240, "despair_shad");
		if(TPRN == who){
			write("You send yourself into a depression.\n");
			return 1;
			}
		else{ 
		     	TELL(target, "You are overwhelmed by a feeling of "+
			"depression. You lose your will to fight!\n");
			return 1;
			}
		TPRSP(-DESPAIR_COST);
		}
	}
int calm(){
   object *ob;
   int i,j;
	    if(check_level(CALM_LVL)){ return 1;}
	    if(check_cost(FCC_COST)){ return 1;}
	    ob= all_inventory(ENV(TP()));
	    j= sizeof(ob);
	    for(i=0; i<j; i++){
		if(living(ob[i]) && ob[i]->query_attack()){
		    ob[i]->stop_fight();
		    ob[i]->stop_fight();
		    ob[i]->stop_hunter(1);
		    }
		if(ob[i]->QRN() != TPRN){
		    TELL(ob[i], "You are overwhelmed by a feeling of "+
		    "calmness, and stop fighting.\n");
		    }
		}
		write("You transmit calm into your whole area, causing "+
	    	"everyone to stop fighting.\n");
	    TPRSP(-FCC_COST);
	    return 1;
	    }
