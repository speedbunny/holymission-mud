inherit "obj/npc";
#include "/players/beardy/walhalla/walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("hermes");
    set_alt_name("god");
    set_race("god");

    set_short("hermes");
    set_long("This is Hermes. A quick looking semi-god" +
             "with his large combat boots.\n");
    set_gender(1);

    load_a_chat(10,
        ({"Hermes says: It's time to go, so don't keep me up.\n",
          "Hermes says: I am the post office of the gods, i am in a hurry.\n",
          "Hermes says: Oh my god, please zap this stupid players.\n",
          "Hermes says: Get away.\n",
          "Hermes pushes you.\n"
        }));

    set_level(25);
    set_hp(3500);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(0);
    set_aggressive(1);
    add_money(4000);

    set_spell_mess1("");
    set_spell_mess2("HHHHHHOOOOOOOOOOPPPPPPPP !!!\n" +
		    "Hermes hops around you and hits you in your back....");
    set_chance(30);
    set_spell_dam(40);

    CO("hboots");
    init_command("wield boots");
  }
}
