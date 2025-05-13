
/* ------------------------------------------------------------------- 
   fang.c now completly recoded by whisky the gnome
   ------------------------------------------------------------------- */

#define TP this_player()
#define E environment
#include "/obj/lw.h"

inherit "/obj/treasure";


reset(int arg) 
{
  if (!arg)
  { 

    set_name("fang");
    set_alias("stone-fish fang");
    set_short("A stone-fish fang");
    set_value(100); 
    set_weight(1);
    set_long("This is stone fang of the dangerous stone-fish,\n"+
             "but it's also a great weapon against your enemies.\n"+
             "Just type <stinger> <name> * grin *, or just <stinger>\n"+ 
             "during the fight to inflict bad damage to your opponent.\n"+
             "But remember, it's only for a single use.\n");
  }
}

init() 
{
   ::init();
   if (E(E(this_object())))
        add_action("fcn_stinger","stinger");
}

static nomask int
fcn_stinger(string victim) 
{
  object mob;
  string *prop;
  
   if (!stringp(victim))
      mob = TP->query_attack();
   else 
      mob = present(victim,E(TP));
  prop = environment(TP)->query_property();

  if (sizeof(prop) && member_array("no_fight",prop)!=-1)
   {
         write("The Gods protect this place.\n");
         return 1;
   }
   call_out("stinger_victim",2,mob);
   return 1;
}

static nomask int
stinger_victim(object mob)
{
  if (objectp(mob) && living(mob) && E(mob)==E(TP)) 
  {

    say(lw(TP->query_name()+" sticks the dangerous fang into "
      + mob->query_name()+"'s skin! As the poison slowly warms "
      + mob->query_possessive()+" body, "+mob->query_name()
      + " growls from pain!\n"),mob);
     tell_object(mob,TP->query_name()
                 + " sticks a stonefish-fang into your body.\n");
     write("You stick the fang into "+mob->query_name()+".\n");
     TP->attack_object(mob); 
     if (TP->query_attack() && TP->query_attack() == mob)
     {
         mob->add_poison(20+random(15));
        if (living(mob)) mob->hit_player(50,7);
        TP->set_vis();
        destruct(this_object());
     }
     return 1;     /* in any case if the destruct is not successful */
   }
  return 0;
}






