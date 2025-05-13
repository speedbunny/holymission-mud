/*
 * the shadow modifies the savings by 20
 */
inherit "/obj/std_shadow";
#include "/spells/spell.h"

varargs int start_shadow(object who, int time, int level)
{
    set_effect_msg("protection from cold");
    who->modify_resistance( COLD,20);
    return ::start_shadow(who,time,"cold",0);
}

void end_shadow(object ob)
{
   me->modify_resistance( COLD,-20);
   tell_object(me,"Your protection from cold wears off.\n");
   ::end_shadow(ob);
}


int cold()
{
	return 1;
}
