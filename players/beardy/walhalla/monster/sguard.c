inherit "obj/npc";
#include "../walhalla.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("skeleton guard");
    set_alt_name("guard");
    set_race("undead");

    set_short("skeleton guard");
    set_long("It's long bones are hanging all around and it doesn have\n" +
             "a nice appearance. You see one eye in its hands and the\n" +
             "rotten flesh smells really bad.\n");
    set_gender(0);

    set_level(20);
    set_attacks_change(100);
    set_attacks(2);
    set_dodge(10);    

    set_al(-200);
    set_aggressive(1);
    add_money(0);

    set_spell_mess1("");
    set_spell_mess2("");
    set_chance(30);
    set_spell_dam(50);

  }
}
