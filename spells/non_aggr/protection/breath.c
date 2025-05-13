/*
 * the shadow modifies the savings by 20
 */
inherit "/obj/std_shadow";
#include "/spells/spell.h"

varargs int start_shadow(object who, int time, int level)
{
    set_effect_msg("protection from breath");
    who->modify_resistance( BREATH,20);
    return ::start_shadow(who,time,"breath",0);
}

void end_shadow(object ob)
{
   me->modify_resistance( BREATH,-20);
   tell_object(me,"Your protection from breath wears off.\n");
   ::end_shadow(ob);
}

int breath()
{
	return 1;
}
