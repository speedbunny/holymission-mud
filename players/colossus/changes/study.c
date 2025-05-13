#include "/players/colossus/guild/defines.h"
#include "/players/colossus/guild/lib/check_cost.h"
#include "/players/colossus/guild/lib/check_attack.h"
#include "lw.h"

int alcheck(object ob){
    string alignment;
    int al;

    al = (int)ob->query_alignment();

    switch(al){
    case -999999 .. -1000:
	alignment = " makes the devil look good";
	break;
    case -999 .. -501:
	alignment = " has a heart as dark as a void";
	break;
    case -500 .. -201:
	alignment = " is malicious";
	break;
    case -200 .. -41:
	alignment = " is heading towards the dark side";
	break;
    case -40 .. 40:
	alignment = " is neither good nor evil";
	break;
    case 41 .. 200:
	alignment = " is heading towards the light";
	break;
    case 201 .. 500:
	alignment = " is a warrior of the Light";
	break;
    case 501 .. 1000:
	alignment = " is a true champion of goodness";
	break;
    case 1001 .. 999999: 
	alignment = " makes the saints look bad";
	break;
    default:
	alignment = " has a buggy alignment";
	break;
    }

    write(CAP(ob->query_pronoun())+alignment+".\n");
    return 1;
}

int accheck(object ob){
    int ac;
    string aclass;


    ac = (int)ob->query_ac();

    switch(ac){
    case 0:aclass=" is totally unarmoured";
	break;
    case 1 .. 3:aclass=" has minimal protection";
	break;
    case 4 .. 7:aclass = " is decently armoured";
	break;
    case 8 .. 12:aclass=" is well armoured";
	break;
    case 13 .. 17:aclass=" is very well armoured";
	break;
    case 18 .. 9999:aclass=" is a walking fortress";
	break;
    default:aclass=" has got a screwed ac";
	break;
    }
    write(capitalize(ob->query_pronoun())+aclass+".\n");
    return 1;
}

int levcheck(object ob){
    int lev;
    string level;

    lev = (int)ob->query_level();

    switch(lev){
    case 1 .. 3:level=" is a puny wimp";
	break;
    case 4 .. 7:level=" is as strong as your average person";
	break;
    case 8 .. 12:level=" is slightly more powerful than an average person";
	break;
    case 13 .. 16:level=" is quite strong";
	break;
    case 17 .. 20:level=" is very strong";
	break;
    case 21 .. 25:level=" can do some serious damage to you";
	break;
    case 26 .. 29:level=" is very dangerous to mess around with";
	break;
    case 30 .. 50:level=" can almost certainly kill you";
	break;
    case 51 .. 999:level=" will definitely be your death";
	break;
    }
    write(ob->query_name()+level+".\n");
    return 1;
}

int wccheck(object ob){
    int wc;
    string wcclass;

    wc = (int)ob->query_wc();

    switch(wc){
    case 0:wcclass=" is totally unarmed";
	break;
    case 1 .. 3:wcclass=" is minimally armed";
	break;
    case 4 .. 7:wcclass=" is poorly armed";
	break;
    case 8 .. 12:wcclass=" is decently armed";
	break;
    case 13 .. 16:wcclass=" is quite well armed";
	break;
    case 17 .. 19:wcclass=" is very well armed";
	break;
    case 20 .. 999:wcclass=" can do some really serious damage";
	break;
    default:wcclass=" has got a really screwed wc";
	break;
    }
    write(capitalize(ob->query_pronoun())+wcclass+".\n");
    return 1;
}

int do_study(string arg){
    object target;
    CG;
    if(check_cost(STUDY_COST, STUDY_LEVEL) ){
	write("You are too mentally fatigued for that.\n");
	return 1;
    }
    if(!check_attack(arg) ){
	write("You cannot find any object to study.\n");
	return 1;
    }
    target = check_attack(arg);
    write(lw("You focus on "+
	target->query_name()+" and summons the energy of Time "+
	"and Space to judge "+target->query_objective()+".\n\n"));
    say(lw(
	TP->query_name()+" begins to focus on "+
	target->query_name()+" and a rainbow of energy appears, "+
	"surrounding "+target->query_objective()+".\n"));
    levcheck(target);
    wccheck(target);
    accheck(target);
    alcheck(target);
    TP->restore_spell_points(-STUDY_COST);
    return 1;
}
