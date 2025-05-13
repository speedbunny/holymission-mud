inherit "obj/npc";
#include "../walhalla.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("prisoner");
    set_alt_name("prisoner");
    set_race("human");

    set_short("prisoner");
    set_long("It is a prisoner. He lived for twenty years in his\n" +
             "cell and is very angry about this\n");
    set_gender(1);

    set_level(10+random(15));
    set_attacks_change(random(100));
    set_attacks(random(6));    
    set_dodge(random(30));
    set_fol_change(50+random(50));
    set_rid_change(random(10));

    set_al(-1*random(400));
    set_aggressive(1);
    add_money(1);

    set_spell_mess1("");
    set_spell_mess2("PNOK - PNOK - PNOK\n" +
                    "That was an tricky combination....");
    set_chance(random(100));
    set_spell_dam(20+random(30));

  }
}
