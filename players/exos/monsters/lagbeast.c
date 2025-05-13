inherit "obj/monster";
#include "defs.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("lagbeast");
    set_alt_name("lag");
    set_alias("beast");
    set_level(25+random(15));
    set_hp(5000+random(5000));
    set_al(0);
    set_gender(0);
    set_race("lagbeast");
    add_money(5000+random(5000));
    set_short("The Lagbeast!");
    set_dead_ob(TO);
    set_prevent_poison(1);
    set_no_ears(1);
    set_number_of_arms(3);
    set_long("This fearsome beast is the number one killer of adventurers.\n"+
      "It appears to be a rather large serpent.  Venom drips from its\n"+
      "fangs, and a LONG, prehensile tail swipes at you.  Its reptilian\n"+
      "form belies its intellegence.  BEWARE!\n");
    set_wc(35+random(40));
    set_ac(50+random(50));
    set_size(5);
    set_aggressive(0);
    load_chat(10,({
	"Lagbeast calculates pi.\n",
	"Lagbeast says: 3.141592654...Hmmm, what next number?\n",
	"Lagbeast says: Average airspeed velocity of an unladen swallow is...\n"
      }));
}

monster_died(ob) {
    if(this_player()->query_immortal()) return;
    shout(this_player()->query_name()+" just killed the dreaded LAGBEAST!\n");
}

hit_player(dam) {
    if(random(100)<25) {
	write("The Lagbeast encircles you with its tail!\n");
	tell_room(environment(),"The Lagbeast encircles "+this_player()->query_name()+" with its tail!\n");
	this_player()->HOLD(TP,random(50)+10);
	return;
    }
    else if(random(100) < 25) {
	write("The Lagbeast bites you!\n");
	tell_room(environment(),"The Lagbeast bites "+this_player()->query_name()+"!\n");
	this_player()->add_poison(random(100)+1);
	return;
    }
    else if (random(100)<50) {
	write("The Lagbeast hits you with a mental bolt!\n");
	this_player()->hit_player(random(100));
	return;
    }
    else if (random(100)<25) {
	write("The Lagbeast did an INSANE amount of damage to you!\n"+
	  "The Lagbeast did an INSANE amount of damage to you!\n"+
	  "The Lagbeast did an INSANE amount of damage to you!\n");
	say("The Lagbeast did an INSANE amount of damage to "+this_player()->query_name()+"!\n"+
	  "The Lagbeast did an INSANE amount of damage to "+this_player()->query_name()+"!\n"+
	  "The Lagbeast did an INSANE amount of damage to "+this_player()->query_name()+"!\n");
	this_player()->hit_player(33+random(67));
	return;
    }
    return ::hit_player(dam);
}
