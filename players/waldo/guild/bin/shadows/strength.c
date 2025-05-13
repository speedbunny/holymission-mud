// Strength Shadow
inherit "obj/std_shadow";
#include "/players/waldo/guild/defs.h"

int new_str;
object mon;
int old_str;

varargs int start_shadow(object target,int time,int str)
{
  old_str=target->query_str();
  new_str=target->query_str()+str;
  target->set_str(new_str);
  mon=target;
  set_effect_msg("Strength "+str);
  return ::start_shadow(target,time,"strength",0);
}

void end_shadow(object target) 
{
    mon->set_str(old_str);
    write("You feel weaker now.\n");
    ::end_shadow(target);
}

query_str()
{
   if (environment(mon)->stat_room())
     return old_str;
   return new_str;
}

query_stats(int x)
{  
  if (environment(mon)->stat_room())
    return mon->query_stats(x);
   if (x == 0) // Strength :)
    return new_str;
   return mon->query_stats(x);
}

int strength_shad() { return 1; }


