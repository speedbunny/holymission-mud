#include "../psi.h"
#define BLEED_LVL 1
#define BLEED_COST 1

int main(string str){
   int BLEED_EFFECT;
   object who;

	if(!str){
	    write("Mindbleed who?\n");
	    return 1;
	    }
	who= present(str, ENV(TP()));
	if(!who){
	    write(CAP(str)+" is no here!\n");
	    return 1;
	    }

	if(who->query_immortal() && !TP()->query_immortal()){
	    write("It would not be wise to mindbleed an immortal. You'd "+
	    "probably die in the process!\n");
	    return 1;
	    }
	if(check_block(str)){ return 1;}
	if(check_armour()){ return 1;}
	check_bleed();
	call_out("bleed", 5, who, str);
	write("You concentrate on bleeding "+CAP(str)+"'s energy.\n");
	return 1;
	}

int bleed(object who, string str){
    int BLEED_EFFECT;
    
	BLEED_EFFECT= (TPQL * 10);
	TPRSP(BLEED_EFFECT);
	if(who->QSP < BLEED_EFFECT){
	   int sp;
	   	sp= who->QSP;
		who->RSP(-sp);
		}
	else{
		who->RSP(-BLEED_EFFECT);
		}
	who->hit_player(0);
	write("You mindbleed some of "+CAP(str)+"'s energy.\n");
	tell_object(who, "You feel some of your energy draining away!\n");
	who->hit_player(0);
	return 1;
	}
