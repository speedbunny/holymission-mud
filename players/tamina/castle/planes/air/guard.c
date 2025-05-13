/*  This is a Guard of Air  */

#include "/players/tamina/defs.h"

inherit "obj/monster";
int count;
object neck;

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("elemental guard");
     set_alt_name("guard");
     set_level(25);
     set_short("An Elemental Guard of Air");
     set_long(
"A powerful elemental guard, animated from the Air that\n"+
"make up this Plane.\n");
     set_race("elemental");
     set_gender(1);
     set_al(-100);
     set_aggressive(1);
     set_wc(33);
     set_ac(17);
     set_spell_mess2("The Air Elemental knocks you aside with a stunning blow !!\n");
     set_spell_mess1("The Air Elemental knocks his opponent to the side !!\n");
     set_spell_dam(55);
     set_chance(33);
     random_move(1);
     count = 0;
  }
  neck = CLO(COBJ + "neck");
  MO(neck, TO);
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

hit_player(dam, type)
{
  object enemy, nec;

  if (random(25) > 22)
  {
    enemy = TO->query_attack();
    if (enemy)
    {
      nec = present("silver necklace", enemy);
      if (nec)
      {
	TOBJ(enemy, "The Air Elemental steals your silver necklace from you !!\n");
	say("The Air Elemental steal the silver necklace from "+enemy->NAME+"!\n");

	MO(nec, TO);
      }
    }
  }
  return ::hit_player(dam, type);
}

