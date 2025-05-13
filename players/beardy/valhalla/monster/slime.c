inherit "obj/npc";
#include "../valhalla.h"

reset(int arg) 
{ ::reset(arg);
  if(arg) return 0;
  set_name("green slime");
  set_alt_name("slime");
  set_race("slime");

  set_short("a green slime");
  set_long("Baaa ! It looks so ugly that you do not want to describe it.\n");
  set_gender(0);

  set_level(16);
  set_attacks_change(100);
  set_attacks(3);    

  set_al(-20);
  set_aggressive(1);
  add_money(0);

  set_spell_mess1("Splatsch !  The slime makes a combat move.");
  set_spell_mess2("Splatsch !  The slime hits you into your face");
  set_chance(30);
  set_spell_dam(70);

}
