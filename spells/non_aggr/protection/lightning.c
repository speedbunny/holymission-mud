/*
 * the shadow modifies the savings by 20
 */
inherit "/obj/std_shadow";
#include "/spells/spell.h"

varargs int start_shadow(object who, int time, int level)
{
    set_effect_msg("protection from lightning");
    who->modify_resistance( ELECTRICITY,20);
    return ::start_shadow(who,time,"lightning",0);
}

void end_shadow(object ob)
{
   me->modify_resistance( ELECTRICITY,-20);
   tell_object(me,"Your protection from lightning wears off.\n");
   ::end_shadow(ob);
}

int lightning()
{
	return 1;
}
