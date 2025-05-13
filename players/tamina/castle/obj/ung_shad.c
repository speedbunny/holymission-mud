/* This is only for Ungoliant  */

inherit "/obj/std_shadow";

#include "/players/tamina/defs.h"

varargs mixed hit_player(int dam, int kind, mixed elem) 
{
  /* 7 special attacks, 0 physical attacks, 6 poison, 5 magic or breath */

  if (me != TP && !random(1) && (kind == 0))
  {
    tell_object(me,
    "The Robe of the Sorceress absorbs "+TPN+"'s attack !\n");
    say(me->RNAME+"'s Robe of the Sorceress absorbs one of "+
        TPN+"'s attacks !\n", me, TP);
    return me->hit_player(0, kind, elem);
  }
  return me->hit_player(dam, kind, elem);
}

int robe_shad()
{
  return 1;
}

object robe_object()
{
  return TO;
}

void end_shadow(object obj)
{
  tell_object(me, "Your body feels more corporeal now.\n");
  ::end_shadow(obj);
}
