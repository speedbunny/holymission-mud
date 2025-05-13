/*  This is Agravain's Rapier  */

#include "/players/tamina/defs.h"

inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("rapier");
    set_alias("sword");
    set_short("A Sharp Rapier");
    set_long(
  "A long, well-sharpened Rapier, made from a strange silver alloy,\n"+
  "which looks as though it could easily slice through the heaviest\n"+
  "of armour plates.\n");
    set_class(8);
    set_value(2500);
    set_weight(2);
    set_hit_func(TO);

}

int weapon_hit(object attacker) 
{
  int amount;

  if (!random(3))
  {
    amount = attacker->query_ac();
    write("Your Rapier slides easily between "+attacker->RNAME+"'s armour !!\n");
    return amount;
  }  
  else
  return random(15);
}
