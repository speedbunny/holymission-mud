inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("poseidon");
    set_alt_name("god");
    set_race("god");

    set_short("poseidon");
    set_long("This is Poseidon, the god of the sea. He is half fish half human\n" +
             "and has got a dangerous looking tail. His condition is like other\n" + 
             "god -> VERY GOOD !\n");
    set_gender(1);
    add_money(6000);

    set_level(30);
    set_hp(5000);
    set_attacks_change(70);
    set_attacks(3);    

    set_al(20);
    set_aggressive(1);

    set_spell_mess1("");
    set_spell_mess2("HHHHHHHHHHIIIIIIIIIIIIIIIIIIIYYYYYYYYYYYYYYYAAAAAAAAOOOOO\n" +
                    "You got an enormous hit by Poseidon's trident");
    set_chance(30);
    set_spell_dam(80);

    CO("trident");
    CO("fshield");
    CO("amulet");
    init_command("powerup");
  }
}
