/*
 * the shadow modifies the savings by 20
 */
inherit "/obj/std_shadow";
#include "/spells/spell.h"

varargs int start_shadow(object who, int time, int level)
{
    set_effect_msg("protection from fire");
    who->modify_resistance( FIRE,20);
    return ::start_shadow(who,time,"fire",0);
}

void end_shadow(object ob)
{
   me->modify_resistance( FIRE,-20);
   tell_object(me,"Your protection from fire wears off.\n");
   ::end_shadow(ob);
}

int fire()
{
	return 1;
}
