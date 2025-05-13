inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("hera");
    set_alt_name("god");
    set_race("god");

    set_short("hera");
    set_long("This is Hera, the wife of Zeus. She is drunken too\n" +
             "and feels very unhappy because Zeus isn't here.\n");

    set_gender(2);

    load_a_chat(10,
        ({"Hera says: This is for Zeus.\n",
          "Hera hiccups.\n",
          "Hera burps.\n",
          "Hera falls onto the floor.\n",
          "Hera says: You disturbed our party, stranger !\nHera says: Therefore you will die !\n",
          "Hera says: Flee if you can.\n"
        }));

    set_level(30);
    set_hp(4500);
    set_attacks_change(40);
    set_attacks(3);    

    set_al(200);
    set_aggressive(1);
    add_money(3000);

    set_spell_mess2("SPLAT ! - Ouch that hurts\n" +
		    "Hera hits you hard with her leg...");
    set_chance(20);
    set_spell_dam(75);
    CO("amulet");
    CO("vine");
    CO("ashield");
    CO("cheart");
    init_command("wear amulet");
    init_command("wear shield");

  }
}
