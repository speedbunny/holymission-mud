inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("huorn");
     set_short("A Huorn");
     set_long(
"This is a huge animated tree that is thundering through the trees\n"+
"at you.  You can see what might be some sort of face etched into the\n"+
"trunk of the tree.  It does not appear to be happy.\n");
     set_level(35);
     set_race("tree");
     set_size(5);
     set_al(-100);
     set_aggressive(1);
     set_wc(25);
     set_ac(25);
     set_spell_mess2("The Huorn swings a branch at your head !!\n");
     set_spell_mess1("One of the Huorn's branches hits its victim on the head !!\n");
     set_spell_dam(35);
     set_chance(9);
     add_money(50);
     set_dead_ob(TO);
  }
}

monster_died(ob)
{
  object bark;

  TRM (E(TO),
   "\nYou manage to finally chop the mad Ent at a vital part of the trunk.\n"+
   "It falls over with a painful creaking noise...\n"+
   "You see a small piece of bark fall off, and float to the ground...\n");

  bark = CLO (COBJ + "bark");
  MO (bark, E(TO));
}
