
inherit "obj/monster"; 

#include "/players/misticalla/defs.h"
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("friendly Cloud Man");
    set_alias("man");
    load_chat(10,({"Man says: Why hello there! How are you doing?\n"}));
    set_level(10); 
    set_ac(3);
    set_wc(6);
    set_al(10); 
    set_race("man"); 
    set_short("A fluffy cloud man"); 
    set_long("He stands before you, yet seems to float around.\n" +
              "He looks friendly, and probably won't bother you.\n" +
	      "You notice he is wearing a flannel shirt and a cap.\n");
    set_spell_mess1("Cloud man turns grey and storms towards you");
    set_spell_mess2("Lightning flies from his fingers and zaps you");
    add_money(50);

   MO(CO(MOBJS+"flannel"),TO);
   MO(CO(MOBJS+"cap"),TO); 
 
   init_command("wear shirt");
   init_command("wear cap");

}
}
