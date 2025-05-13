inherit "obj/npc";
#include "../harbour.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("fisher");
    set_alt_name("fisher");
    set_race("human");

    set_short("fisher");
    set_long("It's a poor fisher eating his fishes.\n");
    set_gender(1);

    set_level(10);
    set_attacks_change(100);
    set_attacks(2);    

    set_al(200);
    set_aggressive(0);
    add_money(20);

    set_spell_mess1("The fisher throws his rod against someone");
    set_spell_mess2("The fisher throws his rod against you");
    set_chance(70);
    set_spell_dam(20);

    CO("rod");
    CO("fish");
  }
}
