inherit "obj/std_shadow";
#include "/players/waldo/guild/defs.h"

object owner;

varargs int start_shadow(object target, int time)
{
  owner = target;
  set_effect_msg("Fireshield");
  return ::start_shadow(target,time,"fshield",0);
  }

void end_shadow()
{
  write("Your fireshield twinkles into nothing.\n");
  ::end_shadow(owner);
  }

int hit_player(int dam, int kind)
{
  if (TP != owner)
  {
    TP->hit_player(dam*2,kind);
    TELL(owner,"You sear "+TP->query_name()+" with your fireshield!\n");
    TELL(TP,"You are seared by "+owner->query_name()+"'s fireshield!\n");
    }
  if (TP->query_immortal())
  {
    write("Fireshield damage : "+(dam*2));
    write(" of type number : "+kind+"\n");
    }
  return (owner->hit_player(dam,kind));
  }

int fshield_shad() { return 1; }
