inherit "obj/npc";
#include "../harbour.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("hunter");
    set_alt_name("hunter");
    set_race("human");

    set_short("hunter");
    set_long("This is one of the hunters of Hucklebery Finn.\n"+
	     "He is very angry about his situation and seems\n"+
	     "be very aggressive.\n");
    set_gender(1);

    set_level(30);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(-20);
    set_aggressive(1);
    add_money(200);

    set_spell_mess1("The hunter hits someone in the stomach");
    set_spell_mess2("The hunter moves his left leg into your stomach");
    set_chance(40);
    set_spell_dam(70);

    CO("chain");
    CO("knife");
    CO("harmour");
    CO("hbag");
    init_command("wield knife");
    init_command("wear armour");

  }
}
