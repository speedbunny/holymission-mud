inherit "obj/weapon";
  int wis;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("Grund's Flail");
    set_alias("flail");
    set_short("Grund's Flail");
    set_long(
  "This is an enormous Flail.\n"+
  "It is basically a huge wooden club, with several\n"+
  "sharp spikes forced into the wood.  It looks very mean\n"+
  "indeed...\n");
    set_class(14);
    set_value(5000);
    set_weight(8);
    set_hit_func(TO);
}

int weapon_hit(object attacker)
{
  wis = TP->WIS;

  if (random(151) > (wis + 50))
  {
    write("The spikes on the Flail flash with a powerful light !!\n"+
	  "Grund's Flail fries "+attacker->NAME+" !!\n");
    say("A blast of power emits from Grund's Flail at "+attacker->NAME+" !!!\n");

    attacker->reduce_hit_point(TP->WIS);
    return (5 + random(wis));
  }
}
