
inherit "/obj/std_shadow";
#include "/players/sourcer/guild/druid.h"

int ac_change;

varargs int start_shadow(object who, int time, int level)
{
    set_effect_msg("barkskin");
	ac_change = 3+level/10;    /* 3-5 */
    return ::start_shadow(who,time,"bark_skin",0);
}

int query_ac()
{
    return( apply(call,me,"query_ac") + ac_change);
}
   
void end_shadow(object ob)
{
   tell_object(me,"Your barkskin wears off.\n");
   ::end_shadow(ob);
}

int bark_shadow()
{
	return 1;
}
