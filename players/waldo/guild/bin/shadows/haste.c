/*
  Haste
  (c) 1996
  Waldo@holy_mission
  */

inherit "/obj/std_shadow";
#define REG_TIME  120

int do_haste;

varargs int start_shadow(object whom, int tim)
{
    set_effect_msg("haste");
    do_haste=1;
    return ::start_shadow(whom,tim,"haste");
}

void end_shadow(object target)
{
  do_haste=0;
  write("You feel yourself SLOWING down.\n");
  ::end_shadow(target);
  }


int hit_player(int dam)
{
  if (!do_haste)
  {
    this_object()->attack();
    return 1;
    }
  this_object()->attack();
  this_object()->attack();
  return 1;
  }

int haste_shad() { return 1; }
