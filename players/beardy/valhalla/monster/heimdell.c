inherit "obj/npc";
#include "../valhalla.h"

reset(int arg) 
{ ::reset(arg);
  if(arg) return 0;
  set_name("heimdell");
  set_alt_name("guard");
  set_race("god");

  set_short("heimdell");
  set_long("This is Heimdell, the god-guard of the bridge of Valhalla.\n"+
	   "He has got a fine looking appearance and a new shaved head.\n"+
	   "While loogking over his fantastic body you recognize a small\n"+
           "piece of wood with lots of cuts in it. You assume that each\n"+
           "cut represents a player that has met a very quick end.\n");
  set_gender(1);

  set_level(20);
  set_attacks_change(100);
  set_attacks(3);    

  set_al(200);
  set_aggressive(0);
  add_money(3000);

  set_spell_mess1("Heimdell makes a combat move");
  set_spell_mess2("Heimdell makes a combat move");
  set_chance(20);
  set_spell_dam(50);

  CO("pkstick");
}
