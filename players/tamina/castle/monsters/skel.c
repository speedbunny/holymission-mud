/*  This is a Skeleton  */

inherit "obj/monster";
object sword,shield;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(!arg) 
  {

     set_name("skeleton");
     set_short("A Skeleton");
     set_long(
"A full set of bleached bones, standing up-right, with a demonic grin on its skull\n");
     set_level(10 + random(9));
     set_al(-500);
     set_aggressive(1);
     set_spell_mess2("The Skeleton jabs you with a sharpened joint.\n");
     set_spell_mess1("The Skeleton pokes its opponent with its elbow!\n");
     set_spell_dam(30);
     set_chance(17);
     set_dead_ob(TO);

  shield = CLO("obj/armour");
   sword = CLO("obj/weapon");

  shield->set_name("shield");
  shield->set_short("A Shield");
  shield->set_long("A strange looking shield, with a bizarre emblem on the front.\n");
  shield->set_weight(3);
  shield->set_value(800);
  shield->set_ac(1);
  shield->set_size(3);
  shield->set_type("shield");

  sword->set_name("sword");
  sword->set_short("A shortsword");
  sword->set_long("A small, flat-bladed sword that looks well-used.\n");
  sword->set_weight(4);
  sword->set_value(1000);
  sword->set_class(15);

  MO(sword, TO);
  MO(shield,TO);
  command("wield sword");
  command("wear shield");

    }

}

monster_died()
{
  TRM (E (TO),
   "\nThe bones fall in a pile on the ground.\n\n");
  destruct(TO);
  return 1;
}

