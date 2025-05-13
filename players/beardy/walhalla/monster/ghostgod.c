inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("ghostgod");
    set_alt_name("ghost");
    set_race("god");

    set_short("mighty ghost-god");
    set_long("It's the famous ghost-god of Walhalla. There is no use" +
             "telling you something about his body, because he has none.\n");
    set_gender(1);

    load_a_chat(10,
          ({"The ghostgod says: Die scum.\n",
            "The ghostgod says: You'll never defeat me.\n",
            "The ghostgod says: I'll kill you for your prying.\n",

            "The ghostgod swears: #@@*\"*&^$%@@*&! !!!!!\n"
          }));

    set_level(40);
    set_hp(8000);
    set_attacks_change(70);
    set_attacks(5);    

    set_al(400);
    set_aggressive(1);

    set_spell_mess2("GGGGGGHHHHHHOOOOOOOOOSSSSSSSSSSHHHHHHHHHHHH !!!!!!!!!");
    set_spell_mess2("He drained you energy.");
    set_chance(45);
    set_spell_dam(120);

    CO("amulet");
    init_command("powerup");
  }
}
