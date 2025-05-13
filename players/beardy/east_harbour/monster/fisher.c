inherit "obj/npc";
#include "../harbour.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("fisher");
    set_alt_name("fisher");
    set_race("human");

    set_short("fisher");
    set_long("It's a poor fisher mending his nets.\n");
    set_gender(1);

    set_level(14);
    set_attacks_change(100);
    set_attacks(2);    

    set_al(200);
    set_aggressive(0);
    add_money(20);

    set_spell_mess1("The fisher throws his net against someone");
    set_spell_mess2("The fisher throws his net against you");
    set_chance(20);
    set_spell_dam(20);

    CO("net");
    CO("fbag");
  }
}
