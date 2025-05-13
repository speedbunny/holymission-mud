// Fireshield Shadow

inherit "obj/std_shadow";
#include "/players/waldo/guild/defs.h"

object mon;

varargs int start_shadow(object target,int time)
{
  mon=target;
  return ::start_shadow(target,time,"fshield",0);
}

void end_shadow(object target) 
{
    write("Your fireshield twinkles away.\n");
    ::end_shadow(target);
}

int hit_player(int dam, int kind)
{
  if (TP!=mon)
    TP->hit_player(dam*2,kind);
  ME("Your fireshield burns "+TP->QNAME+"!\n");
  TELL(TP,"You are burnt badly by "+mon->QNAME+"'s fireshield.\n");
  return (mon->hit_player(dam,kind));
  }

int fshield_shad() { return 1; }
