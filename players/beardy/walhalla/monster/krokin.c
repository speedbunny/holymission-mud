inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("krokin");
    set_alt_name("god");
    set_race("god");

    set_short("krokin");
    set_long("This is god Bacchus, but he is incognito. He is\n"+
             "very drunk now - as usually - but he\n" +
             "is still a good fighter\n");
    set_gender(1);

    set_level(30);
    set_hp(6000);
    set_dex(15);
    set_str(40);
    set_attacks_change(20);
    set_attacks(4);    

    load_chat(30,
             ({ "God Bacchus hiccups.\n",
                "God Bacchus burbs.\n",
                "God Bacchus singing a song : Falala lala bi bop alula....\n",
                "God Bacchus shouts : I need more vine and girls. Where to hell are they ?\n",
                "God Bacchus says : Quod licet iovi, non licet bovi.\n",
                "God Bacchus puts his arms around you and gives you a big kiss.\n",
                "God Bacchus pukes onto the floor.\n",
                "God Bacchus gulps down a bottle of vine.\n"
              }));

     load_a_chat(20,
           ({ "God Bacchus pukes into you face.\n",
                "God Bacchus says : You have no chance, baby !\n",
                "God Bacchus says : Go home newbie !\n",
                "God Bacchus screams in pain as you hit him.\n",
                "God Bacchus suffers form intoxication.\n",
                "God Bacchus starts singing his war song : See him, get him , make him join the dead !\n",
                "God Bacchus kicks you in your ass.\n",
              }));

    set_al(400);
    set_aggressive(1);
    add_money(1);


    set_spell_mess1("");
    set_spell_mess2("CRASH ! He hit you head with an empty vine bottle...");
    set_chance(25);
    set_spell_dam(35);

    CO("vine");
    CO("amulet");
    init_command("powerup");
  }
}
