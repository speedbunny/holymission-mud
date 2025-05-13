/*  This is a Guard of Fire  */

#include "/players/tamina/defs.h"

inherit "obj/monster";
int count;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("elemental guard");
     set_alt_name("guard");
     set_level(25);
     set_short("An Elemental Guard of Earth");
     set_long(
"A powerful elemental guard, animated from the solid Earth that\n"+
"make up this Plane.\n");
     set_race("elemental");
     set_gender(1);
     set_al(-100);
     set_aggressive(1);
     set_wc(33);
     set_ac(17);
     set_spell_mess2("The Earth Elemental!!\n");
     set_spell_mess1("Bolts of flame streak from the Fire Elemental's fingers!\n");
     set_spell_dam(55);
     set_chance(33);
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

