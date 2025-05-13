/*  This is a Guard of Water  */

#include "/players/tamina/defs.h"

inherit "obj/monster";
int count;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Elemental Guard");
     set_alt_name("guard");
     set_level(25);
     set_race("elemental");
     set_short("An Elemental Guard of Water");
     set_long(
"A powerful elemental guard, animated from the waters that\n"+
"make up this Plane.\n");
     set_gender(1);
     set_al(-100);
     set_aggressive(1);
     set_wc(33);
     set_ac(17);
     set_spell_mess2(
"Water Elemental bashes you with a powerful fist !!\n");
     set_spell_mess1(
"The Water Elemental's fists connects solidly with his opponent !\n");
     set_spell_dam(55);
     set_chance(28);
     random_move(1);
     count = 0;
  }
}

heart_beat()
{
  if (++count > 4)
  {
    random_move();
    count = 0;
  }
  ::heart_beat();
}
