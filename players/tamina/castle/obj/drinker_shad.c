inherit "/obj/std_shadow";

#include "/players/tamina/defs.h"

varargs mixed hit_player(int dam, int kind, mixed elem) 
{
  if (me != TP && (kind == 0))
  {
    tell_object(me,
    "Drinker supplies you with more blood !!\n");
    return me->hit_player((dam - 5), kind, elem);
  }
  return me->hit_player(dam, kind, elem);
}

varargs int start_shadow(object who, int time)
{
  set_effect_msg("drinker");
  return ::start_shadow(who, time, "drinker", 0);
}

int healer()
{
  this_player()->heal_self(random(3));
}

int drinker_shad()
{
  return 1;
}

object drinker_object()
{
  return TO;
}

void end_shadow(object obj)
{
  tell_object(me, "Your blood's pace slows to normal, when you remove Drinker.\n");
  ::end_shadow(obj);
}
