#include "/players/trout/psi/psi.h"

#define SAY_LVL 1
#define EMOTE_LVL 9
#define MONEY_LVL 17
#define TRADE_LVL 25
#define SAY_COST 50
#define EMOTE_COST 50
#define MONEY_COST 200
#define TRADE_COST TPQMSP


main (string str){
   object target, *ob1, trade_thing, exchange;
   string who, type, what, trade_name;
   int not_here, i, j, amt, value;
	if(!str){
	not_here=0;
	    write("Useage: Suggest <who> to <type> <action>\n");
	    return 1;
	    }
	sscanf(str, "%s to %s %s",who,type,what);
	if(!who){
	    write("Who do you want to suggest to do anything?\n");
	    return 1;
	    }
	if(!type){
	    write("Suggest "+CAP(who)+" to do what?\n");
	    return 1;
	    }
	if(!what){
	    write("Suggest "+CAP(who)+" to "+type+" what?\n");
	    return 1;
	    }
	target=present(who, ENV(TP()));
	if(!target){
	    write(CAP(who)+" is not here!\n");
	    return 1;
	    }
	if(target->query_immortal() && !TP()->query_immortal()){
	    write("You doubt that you could suggest an immortal to do "+
	    "much of anything, except maybe kill you!\n");
	    return 1;
	    }
	if(check_block(who)){ return 1;}
	check_bleed();
	if(type=="say"){
	    if(check_level(SAY_LVL)){ return 1;}
	    if(check_cost(SAY_COST)){ return 1;}
	    write("You pull "+CAP(who)+" into a hypnotic trance, and convince"+
	    " "+target->query_objective()+" to say: "+what+".\n");
	    TELL(target, CAP(TPRN)+" suggests that you say "+what+". Oddly "+
	    "enough, it seems like a good idea at the moment. So you do "+
	    "it.\n");
	    command("say "+what+"\n", target);
	    TPRSP(-SAY_COST);
	    }
	if(type=="emote"){
	    if(check_level(EMOTE_LVL)){ return 1;}
	    if(check_cost(EMOTE_COST)){ return 1;}
	    write("You pull "+CAP(who)+" into a hypnotic trance and convince"+
	    " "+target->query_objective()+" to emote: "+what+".\n");
	    TELL(target, CAP(TPRN)+" suggest that you "+what+". Oddly enough,"+
	    " it seems like a good idea at the moment. So you do it!\n");
	    TLR(ENV(TP()), CAP(who)+" "+what+".\n");
	    TPRSP(-EMOTE_COST);
	    }

	if(type=="give"){
	    if(check_level(MONEY_LVL)){ return 1;}
	    if(check_cost(MONEY_COST)){ return 1;}
	    if(target->query_npc()){
		write(CAP(target->query_name())+" is too unfriendly to get "+
	  	"any money from.\n");
		return 1;
		}
	    amt= (TP()->query_chr()+TPQL)*10 + TPQLL*5;
	    if(target->query_money()<amt){
		amt=target->query_money();
		}
	    write("You pull "+CAP(who)+" into a hypnotic trance and convince"+
	    " "+target->query_objective()+" to give you "+amt+" coins.\n");
	    TELL(target, CAP(TPRN)+" suggests that you give him some money."+
	    " Oddly enough, it seems like a good idea at the moment. So, "+
	    "you do it!\n");
	    command("give "+amt+" coins to "+TPRN+"", target);
	    }
	if(type=="trade"){
	    if(check_level(TRADE_LVL)){ return 1;}
	    if(check_cost(TRADE_COST)){ return 1;}
	    trade_name=what;
	    trade_thing=present(trade_name, target);
	    exchange=0;
	    if(!present(trade_name, target)){
		write(CAP(who)+" doesn't have a "+trade_name+".\n");
		return 1;
		}
	    ob1=all_inventory(TP());
	    j=sizeof(ob1);
	    for(i=0; i<j; i++){
		if(ob1[i]->query_value() > trade_thing->query_value()*2){
		    exchange=ob1[i]->query_name();
		    }
		}
	    if(exchange==0){
		write("You don't have anything worth enough to trade for "+
		""+CAP(who)+"'s "+trade_name+".\n");
		return 1;
		}
	    write("You pull "+CAP(who)+" into a hypnotic trance and convince"+
	    " "+target->query_possessive()+" to trade "+
	    ""+target->query_possessive()+" "+trade_name+" for your "+
	    ""+exchange+".\n");
	     TELL(target, CAP(TPRN)+" suggests that you trade your "+
	     ""+trade_name+" for "+TP()->query_possessive()+" "+exchange+". "+
	     "Oddly enough, it seems like a good idea at the moment. So, "+
	     "you do it!\n");
	     command("give "+trade_name+" to "+TPRN+"", target);
	     command("give "+exchange+" to "+who+"", TP());
	     }
	if(not_here>0){
	    ob1=all_inventory(target);
	    j=sizeof(ob1);
	    for(i=0; i<j; i++){
		if(ob1[i]->id("rsoul")){
		    destruct(ob1[i]);
		    }
		}
	}
	return 1;
	}

