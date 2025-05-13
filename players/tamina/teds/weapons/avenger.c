inherit "obj/weapon";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("unholy avenger");
    set_alias("avenger");
    set_short("An Unholy Avenger");
    set_long(
  "This black blade radiates evil and glows with a black aura.\n"+
  "You think that only a terribly evil person could wield this sword...\n");
    set_type(3);
    set_class(17);
    set_value(2000);
    set_weight(4);
    set_hit_func(TO);
}

int id(string str)
{
  return str == "avenger" || str == "unholy avenger" || str == "sword";
}

int wield(string arg) 
{
  if (!id(arg)) return 0;

  if (this_player()->query_alignment() >= -100) 
  {
    write("You must be very evil to wield this sword.\n");
    return 1;
  } 
  if (::wield(arg)) 
  {
    write("The unholy avenger pulses with a black radiance.\n");
  }
  return 1;
}

int weapon_hit(object attacker)
{
  int amount;

  amount = (-(TP->query_alignment()))/2;
  if (amount > 25)
    amount = 25;
  return amount;
}

