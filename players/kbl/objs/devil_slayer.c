/* This sword is for the "Fire Spirit" only. */

inherit "obj/weapon";
#include "/players/kbl/header/T.h"

void reset(int arg)
{
  ::reset(arg);
  if(!arg)
  {
   set_short("Fire Slayer");
   set_long(
     "The gold handles make your heart pound with greed.\n"+
     "You feel a hunger to slay something extremely evil.\n"+
     "There is writing burnt into the glinting blade.\n");
   set_read("Burnt is the molten fear of the warrior who wields the\n"+
             "only weapon that can slay the Fire Spirit.\n");
   set_name("Fire Slayer");
   set_alt_name("sword");
   set_alias("slayer");
   set_value(1500);
   set_weight(3);
   set_class(14);
   set_hit_func(this_object());
  }
}

weapon_hit(ob)
{
  if((environment(this_object())->query_attack())->id("fire spirit"))
  {
   write("You use all your power to smite the Fire Spirit.\n");
   say(CTPRN+" uses the Fire Slayer to smite the Fire Spirit.\n");
   return 100;
  }
  write("The SunGoddess appears before you.\n"+
        "The SunGoddess says: You were asked to use this weapon on the\n"+
        "                     Fire Spirit. Since the creature you have asked\n"+
        "                     to kill was not him, The sword must be taken\n"+
      "                     from you.\n"+
      "The Fire Slayer dissolves in your hands.\n");
  say("The SunGoddess appears before "+CTPRN+"\n"+
      "The Fire Slayer dissolves in "+CTPRN+"'s hands.\n");
  destruct(this_object());
  ob->stop_fight();   /* makes "peace" */
  environment(this_object())->stop_fight();
  return;
}
