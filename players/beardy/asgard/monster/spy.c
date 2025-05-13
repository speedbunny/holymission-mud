inherit "obj/npc";
#include "../asgard.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("spy");
    set_alt_name("spy");
    set_race("human");

    set_short("spy");
    set_long("This is one of Niflheim's spies. These are very\n"+
             "nasty humans, who love nothing more than chasing\n"+
             "others and merely not only chasing.\n");
    set_gender(1);

    set_level(5+random(10));
    set_attacks_change(50);
    set_attacks(2);    

    set_al(-70);
    set_aggressive(1);
    add_money(100+random(300));

    set_spell_mess1("The spy makes a combat move");
    set_spell_mess2("The spy makes a combat move");
    set_chance(20+random(20));
    set_spell_dam(30+random(30));
  }
}
