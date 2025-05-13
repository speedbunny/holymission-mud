
/* Coded by Tinman */
inherit "obj/weapon";
#include "/players/tinman/area/defs.h"

int i;

void reset(int arg) 
{
    if (!arg) 
    {

	set_name("black dragon");
	set_id("dragon");
	set_short("Black Dragon");
	set_alt_name("spear");
	set_long("This is the mighty Black Dragon forged by the war god Guan Yu"+
". It is a spear with a heavy broad saber at the point end. It looks as if it"+
" weights a ton. It has a small black dragon eched on both side of the blade."+
" It looks as if it will cut through anything it hits\n");
	set_value(200000);
set_two_handed();
	set_weight(5);
	set_class(20);
	set_type(1);
	set_hit_func(this_object());
    }
}

weapon_hit(attacker) 
{
    write(
	BS("Your Black Dragon cuts a pound of flesh off of "+attacker->query_name()+"'s body!"));
    say(BS(
	"You can see the power of the Black Dragon cut a pound of flesh off "+
	""+attacker->query_name()+"'s body!"));

    if (random(100) < 20 && !i)
    {
	call_out("second_hit",1,({attacker,this_player()}));
	i = 1;
    }  
    return random(15);
}
second_hit(*victims)
{
    object tp;
    object att;

    tp = victims[1]; 
    att = victims[0]; 

    if (objectp(att) && living(att) && objectp(tp) && living(tp) &&
      environment(att)== environment(tp))
    {
	tell_object(tp,"\n** You stun your enemy for an extra attack **\n");
	tp->attack();
    }
    i = 0;
}

