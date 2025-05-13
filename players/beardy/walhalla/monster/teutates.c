inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("teutates");
    set_alt_name("god");
    set_race("god");

    set_short("teutates");
    set_long("This is the Gallic god Teutates. Today he has " +
             "a date with Hera and doesn't want to be " +
             "distrubed by you. Btw. he is the best known " +
             "fighter god of the Gallic.\n");
    set_gender(1);

    set_level(35);
    set_hp(7500);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(250);
    set_aggressive(1);
    add_money(6000);

    set_spell_mess1("");
    set_spell_mess2("TTTTTSSSSSSSSUUUUUUUUUMMMMMMMMMMMMM\n" +
                    "What a mighty attack by Teutates...");
    set_chance(65);
    set_spell_dam(30);

    CO("amulet");
    init_command("powerup");
  }
}
