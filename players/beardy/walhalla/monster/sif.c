inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("sif");
    set_alt_name("god");
    set_race("god");

    set_short("Sif");
    set_long("This is Sif. The god of justice and law.\n" +
             "He himself isn't tough at all, but he can\n" +
             "call help if you are going to attack him.\n");
    set_gender(1);

    set_level(20);
    // set_hp();
    set_attacks_change(100);
    set_attacks(2);    

    set_al(2000);
    set_aggressive(0);
    add_money(1);

//    set_spell_mess2("");
//    set_chance();
//    set_spell_dam();

  }
}
