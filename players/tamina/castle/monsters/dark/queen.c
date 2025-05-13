#include "/players/tamina/defs.h"
#define AO attacker_ob

inherit "/obj/monster";
object crown;

reset(arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Darkling Queen");
	set_alias("queen");
	set_alt_name("darkling");
	set_race("darkling");
	set_gender(2);
	set_level(27);
	set_short("The beloved concubine of the Lord of Darkness");
	set_long("A tall figure who simply exudes passionate charm.\n");
	set_al(-400);
	set_aggressive(1);
	set_weight(3);
	set_wc(27);
	set_ac(15);
	set_dead_ob(TO);

     	crown = CLO ("obj/armour");

    crown->set_name("crown of darkness");
    crown->set_alias("crown");
    crown->set_type("helmet");
    crown->set_short("Crown of Darkness");
    crown->set_long(
"This crown seems to be created out of encrusted, solid darkness.\n"+
"It looks very peculiar, since it is almost invisible on your head.\n");
    crown->set_ac(1);
    crown->set_weight(2);
    crown->set_value(550);
    crown->set_arm_light(-1);

	MO (crown, TO);
	command("wear crown");

	}

attack()
{
  object victim;
  string att_name;
  int p;

  if (::attack())
  {
    victim = TO->query_attack();
    att_name = victim->NAME;

    switch (random(101))
    {
  case 0:
    return;
  case 1 .. 31:
    say("The Darkling Queen shoots bolts of bristling Darkness at "+att_name+" !!\n");
    victim->hit_player(30 + random(31));
    break;
  case 32 .. 40:
    say("The Queen of Darkness boils the blood of "+att_name+" !!\n");
    victim->hit_player(40 + random(41));
    break;
  case 41 .. 43:
    say("The Queen blasts the room in freezing Darkness !!\n");
    victim->hit_player(50 + random(51));
    break;
  default:
    return;
    }
  return 1;
  }
}

monster_died()
{
  TRM (E (TO),
   "\nThe swirling darkness arond the Queen suddenly dissipates to nothingness.\n");

  destruct(TO);
  return 1;
}
