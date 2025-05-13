inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("wotan");
    set_alt_name("god");
    set_race("god");

    set_short("Wotan");
    set_long("This is Wotan the god of battle and fight. He is a \n" +
             "master in his skills and look REALLY tought. I think\n" +
             "i dont have to write a lot down here, because he is\n" +
             "AGGRESSIVE agains stranges.\n");
    set_gender(1);

    set_level(40);
    set_hp(8000);
    set_attacks_change(90);
    set_attacks(5);    

    set_al(300);
    set_aggressive(1);
    add_money(10000);

    set_spell_mess2("TRUPACCCCC TROCCCCC\n" +
                    "Wotan made his special attack....");
    set_chance(65);
    set_spell_dam(40);

    CO("wsword");
    CO("warmour");
    init_command("powerup");

  }
}
