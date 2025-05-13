inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("guard");
    set_alt_name("porter");
    set_race("semi-god");
    set_alias("semi");
    set_short("grim guard");
    set_long("This is a grimm semi-god porter. His appearance\n" +
             "is rather yours than a real god and his weaponary\n" +
             "is not very good too. But watch out he has got a\n" +
             "very good constitution.\n");

    set_gender(1);

    load_chat(8,
         ({ "The guard says: Oh what a cruel castle. I wish i could guard somewhere else.\n",
            "The guard bursts out in tears.\n",
           "The guard starts to whine.\n",
        }));

    load_a_chat(8,
         ({ "The guard says: Yes, kill me, so i don't have to stay here anymore.\n",
            "The guard says: It wount be easy.\n",
            "The guard grins evilly.\n",
            "The guard says: Go home newbie.\n",
            "The guard says: No luck today.\n"
         }));

    set_level(10);
    set_hp(2000);
    set_attacks_change(100);
    set_attacks(1);    

    set_al(0);
    set_aggressive(0);
    add_money(700);

    set_spell_mess1("");
    set_spell_mess2("HHHHHHRRRRRRRSSSCCCCHHHAAAAKKKK !!!! An unusual attack for a guard...");
    set_chance(10);
    set_spell_dam(30);

  CO("cure_potion");
  }
}
