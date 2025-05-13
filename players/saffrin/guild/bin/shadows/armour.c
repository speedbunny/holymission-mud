// Armour Shadow
inherit "obj/std_shadow";
#include "/players/waldo/guild/defs.h"

int new_ac;
int old_ac;
object mon;

varargs int start_shadow(object target,int time,int adjustment)
{
  old_ac=target->query_n_ac();
  new_ac=target->query_n_ac()+adjustment;
  target->set_n_ac(new_ac);
  mon=target;
  set_effect_msg("armour "+adjustment);
  return ::start_shadow(target,time,"armour",0);

}

void end_shadow(object target) 
{
    mon->set_n_ac(old_ac);
    write("You feel less protected.\n");
    ::end_shadow(target);
}

int armour_shad() { return 1; }

