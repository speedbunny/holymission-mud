inherit "obj/weapon";
  string name;       
  int con, factor;   

#include "lw.h"
#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;
 
  set_name("sacrificial knife");
  set_alias("knife");
  set_short("Sacrificial Knife");
  set_long(
"A wickedly curving blade with a blood-red stained, ivory hilt.  \n"+
"The light reflecting from the blade seems to be tainted red.  You \n"+
"definitely feel a powerful surge of magic course through the enchanted \n"+
"blade.  When you hold it in your hand, you suddenly feel an unnatural \n"+
"urge you spill oodles of blood... There must be some sort of magical \n"+
"power involed with this weapon.\n");
  set_class(9);
  set_value(2500);
  set_weight(3);
  set_hit_func(TO);
}

int weapon_hit(object attacker)
{
  name = attacker->NAME;
  con = TP->CON;  
  factor = (42 - con);

  if (random(51) > factor)
  {
    write(lw("You drain "+name+"'s body of blood, leaving a dried-out husk.\n"));
    say(lw(TPN+" drains "+name+"'s body of blood, till "+attacker->QPRO+" looks like a dried-out husk!!\n"));

   attacker->reduce_hit_point(random(factor*1) + 5);
    if (!random(factor))
    {
      write("You feel the blood drain into your soul.\n");
     this_player()->heal_self(factor / 2);
    }
    return factor;
  }
}
