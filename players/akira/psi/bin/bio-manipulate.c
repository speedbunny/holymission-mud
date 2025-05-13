#include "/players/akira/psi/psi.h"
#define BLIND_LVL 7
#define ITCH_LVL 16
#define MUTE_LVL 19
#define PAIN_LVL 20
#define POISON_LVL 26
#define BLIND_COST 30
#define MUTE_COST 50
#define PAIN_COST 75
#define ITCH_COST 60
#define POISON_COST 200

int main(string str){
   object shad, target, *ob;
   int i, j;
   string type, who;
	if(!str){
	    write("What kind of bio-manipulation do you what to perform?\n");
	    return 1;
	    }
	sscanf(str, "%s in %s", type, who);
	if(!who){
	    write("Bio-manipulate who?\n");
	    return 1;
	    }
	if(check_block(who)){ return 1;}
	if(check_armour()){ return 1;}
	target= present(who, ENV(TP()));
	if(!target){
	    write(CAP(who)+" is not here!\n");
	    return 1;
	    }
	if(target->query_immortal() && !TP()->query_immortal()){
	    write("You decide that bio-manipulating an immortal is not "+
	    "very wise. Next time try using that great brain power you "+
	    "have!\n");
	    return 1;
	    }
	if(type=="blind"){
	    if(check_level(BLIND_LVL)){ return 1;}
	    if(check_cost(BLIND_COST)){ return 1;}
	    if(target->query_real_name() == TPRN){
		write("You don't want to blind yourself!\n");
		return 1;
		}
	    if(!TP()->query_attack()){
	        target->hit_player(0);
		}
	    shad= CO(PSI+"/shadows/blind_shad");
	    shad->start_shadow(target, 15);
	    write("You blind "+CAP(who)+" causing "+target->query_possessive()+" to "+
	    " swing wildly.\n");
	     TELL(target, "You become blinded. Unable to see, you swing "+
	     "wildly at your opponent.\n");
	     TPRSP(-BLIND_COST);
	     return 1;
	     }
	if(type=="itch"){
	    if(check_level(ITCH_LVL)){ return 1;}
	    if(check_cost(ITCH_COST)){ return 1;}
	    if(!target->query_armour()){
		write(CAP(who)+" is not wearing any armour.\n");
		return 1;
		}
	     else{
		call_out("itch_say", 1, target);
		call_out("itch", 3, who, target);
		write("You cause "+CAP(who)+"'s skin to start itching.\n");
		tell_object(target, "You skin begins to itch.\n");
		TPRSP(-ITCH_COST);
		return 1;
		}
	    }
	if(type=="mute"){
	    if(check_level(MUTE_LVL)){ return 1;}
	    if(check_cost(MUTE_COST)){ return 1;}
	    if(target->query_real_name() == TPRN){
	   	write("Why would you want to mute yourself?\n");
		return 1;
	    	}
	     shad= CO(PSI+"/shadows/mute_shad");
	     shad->start_shadow(target, 9);
	     write("You silence "+target->query_name()+"'s vocal cords!\n");
	     TPRSP(-MUTE_COST);
	     return 1;
	     }
	if(type=="pain"){
	    if(check_level(PAIN_LVL)){ return 1;}
	    if(check_cost(PAIN_COST)){ return 1;}
	    if(target->query_real_name()==TPRN){
		write("Why would you want to inflict pain on yourself? Are "+
		"you some sort of sick masochist?\n");
		return 1;
		}
	    if(!TP()->query_attack()){
	        target->hit_player(0);
		}
	    write("You send a jolt of pain through "+target->QRN()+""+
	    "'s body, causing "+target->query_objective()+" to writhe in "+
	    "agony!\n");
	    tell_object(target, "A shockwave of pain runs through your "+
	    "entire body. You struggle of resist, but can do little more "+
	    "than writhe in agony!\n");
	    target->hold(TP(), 9);
	    target->hit_player(25);
	    TPRSP(-PAIN_COST);
	    return 1;
	    }
	if(type=="poison"){
	   int POISON;
	    if(check_level(POISON_LVL)){ return 1;}
	    if(check_cost(POISON_COST)){ return 1;}
	     if(!TP()->query_attack()){
		target->hit_player(0);
		}
	    POISON= (((TPQL+TPQLL)*2)+10);
	     target->add_poison(POISON);
	     write("You manipulate "+target->QRN()+"'s body to secrete "+
	     "toxic doses of natural chemicals.\n");
	     tell_object(target, "Your body begins to burn from the "+
	     "inside!\n");
	     TPRSP(-POISON_COST);
	     return 1;
	     }
	}
int itch_say(object target){
	TELL(target, "The itching is becoming unbearable!\n");
	return 1;
	}
int itch(string who, object target){
   object *ob;
   int i, j, k;
   string armour;
	ob= target->query_armour();
	j= sizeof(ob);
	k= random(j);
	armour= ob[k]->query_name();
	command("remove "+armour+"", target);
	command("remove "+ob[k]->query_name()+"", target);
	TLR(ENV(TP()), CAP(who)+" removes "+target->query_possessive()+" "+
	""+ob[k]->query_name()+" and scrathces "+target->query_objective()+
	"self.\n");
	return 1;
	}
