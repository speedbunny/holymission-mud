inherit "/obj/std_shadow";
#include "/players/sourcer/guild/druid.h"

object owner;
object targ;
int count;
do_hit();

varargs int start_shadow(object who, int time)
{
    set_effect_msg(" (glowing red) ");
	targ = who;
	count=time;
	do_hit();
    return ::start_shadow(who,0,"heat_a_shad",0);
}

int set_owner(object who) { owner = who; ;return 1; }
object owner() { return owner; }

void end_shadow(object ob)
{
   tell_object(owner,"Your "+targ->query_name()+" is not so hot anymore.\n");
   ::end_shadow(ob);
}

do_hit()
{	
	if(!owner) destruct(this_object());
	else
	{
	tell_object(owner,
		"Your "+targ->query_name()+" is searing HOT.\n");
	owner->hit_player(30,7,({ 1 }) );
	count--;
	if(count>=0) return call_out("do_hit",5);
	else 
	{
		tell_object(owner,"Your "+targ->query_name()+" is not so hot anymore.\n");
		destruct(this_object());
	}
	}
	
}

remove(what)
{
	remove_call_out("do_hit");
	if(owner) owner->remove(what);
	destruct(this_object());
}


int heat_a_shad()
{
	return 1;
}
