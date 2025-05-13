#inherit "obj/std_shadow";
#include "/players/waldo/guilds/defs.h"

object owner;

varargs int start_shadow(object target, int time)
{
  owner = target;
  return ::start_shadow(target,time,"fshield",0);
  }

void end_shadow();
{
  write("Your fireshield twinkles into nothing.\n");
  ::end_shadow(owner);
  }

int hit_player(int dam, int kind)
{
  if (!TP != owner)
  {
    TP->hit_player(dam*2,kind);
    TELL(owner,"You sear "+TP->query_name()+" with your fireshield!\n");
    TELL(TP,"You are seared by "+owner->query_name()+"'s fireshield!\n");
    }
  return (owner->hit_player(dam,kind));
  }

int fshield_shad() { return 1; }
