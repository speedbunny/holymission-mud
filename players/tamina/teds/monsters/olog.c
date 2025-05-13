/*  This is an evil Olog-Hai  ->  Super troll  */

inherit "obj/monster";

#include "/players/tamina/defs.h"

object flail, armour;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

    set_name("Grund, the Olog-Hai");
    set_alt_name("grund");
    set_alias("grund the olog-hai");
    set_race("olog-hai");
    set_short("Grund, the Olog-Hai");
    set_level(45);
    set_size(5);
    set_gender(1);
    set_al(-10);
    set_hp(8000);
    set_wc(50);
    set_ac(16);
    set_spell_mess2("Grund pummels you with his enormous fists.\n");
    set_spell_mess1("Grund flattens his enemies.\n");
    set_spell_dam(35);
    set_chance(30);
    set_aggressive(1);
    add_money(1);
    load_chat(15,
  ({"Grund makes a gutteral bellow at you !!\n",
    "Grund picks his nose.\n",
    "Grund sharpens his Flail...\n",
    "Grund wanders around the room...\n",
    "Grund causes the earth to quake as he wanders around you...\n", }) );
    load_a_chat(30, 
  ({"Grund bellows: What you doing ??\n",
    "Grund says: OUCH!!  Why you hitting me??\n",
    "Grund beats his chest in an alarming display of savagery.\n",
    "Grund runs his hand across his throat, to imply your imminent death.\n",
    "The Olog-Hai jumps up-and-down in fury at you.\n", }) );
    set_dead_ob(TO);

   flail = CLO("/players/tamina/teds/weapons/flail");
  armour = CLO("obj/armour");

  armour->set_name("Grund's Platemail");
  armour->set_alias("platemail");
  armour->set_type("armour");
  armour->set_short("Grund's Set of Platemail");
  armour->set_long(
    "This is the huge set of platemail worn by Grund the Olog-Hai.\n"+
    "You can see that it is not a very expert set of armour, being\n"+
    "only a collection of very rigid sheets of solid iron...\n"+
    "But you imagine it is very protective.\n");
  armour->set_size(5);
  armour->set_weight(9);
  armour->set_value(1000);
  armour->set_ac(4);

  MO(flail, TO);
  MO(armour, TO);

  command("wield flail", TO);
  command("wear armour", TO);
}

void long()
{
  write(
  "This is the largest, and most ugliest looking monster you have ever\n"+
  "seen.  Grund stands at least 16 feet tall right in front of you..\n"+
  "He smells so foul, and looks so fearsome, that you cannot bear to \n"+
  "look at him for any length of time...\n");
  say(TPN+" turns pale, and flees as "+TP->QPRO+" looks at Grund.\n");

  if (TP->LVL < 29)
    TP->run_away();
}

int query_con() { return 70; }
int query_str() { return 80; }
int query_int() { return 20; }

  /* removed due to increased shouts. Limiting shouts to main quest monsters 
    only. sorry tamina. 6-10-95
monster_died(ob)
{
  shout(TPN+" just slew Grund, the evil Olog-Hai !!\n");
}
    */

