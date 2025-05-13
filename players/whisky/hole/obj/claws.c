
/* Coded by Gambit */
/* Thanxs for your help Whisky */
inherit "obj/weapon";
#include "/players/gambit/defs2.h"

int i;

void reset(int arg) 
{
    if (!arg) 
    {

	set_name("wolverine claws");
	set_id("claws");
	set_short("Wolverine Claws");
	set_alt_name("claws");
	set_long(BS("The wolverine claws. This powerful weapon is made out of "+
	    "adamantium steel and can cut through anything. This weapon is made "+
	    "up of three claws, each about a foot long and come straight to a "+
	    "point. The claws itself is lined within a leather glove and feel "+
	    "powerful just wielding it in your hand. Almost to the point of "+
	    "being scary."));
	set_value(4500);
	set_weight(6);
	set_class(10);
	set_type(1);
	set_hit_func(this_object());
    }
}

weapon_hit(attacker) 
{
    write(
      BS("-------------------------------------------------------------")+
      BS("You can feel the power explode from the claws as it rips deep into "+
	""+attacker->query_name()+"'s body! ")+
      BS("-------------------------------------------------------------"));
    say(BS(
	"You can feel the power explode from the claws as it rips deep into "+
	""+attacker->query_name()+"'s body!"));

    if (random(100) < 30 && !i)
    {
	call_out("second_hit",1,({attacker,this_player()}));
	i = 1;
    }  
    return random(15);
}
/*
second_hit(*victims)
{
    object tp;
    object att;

    tp = victims[1]; 
    att = victims[0]; 

    if (objectp(att) && living(att) && objectp(tp) && living(tp) &&
      environment(att)== environment(tp))
    {
	tell_object(tp,"\n** You are changing to your second claw **\n");
	tp->attack();
    }
    i = 0;
}
*/

