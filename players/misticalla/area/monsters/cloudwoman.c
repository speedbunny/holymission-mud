
inherit "obj/monster"; 

#include "/players/misticalla/defs.h"
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("friendly Cloud Woman");
    set_alias("woman");
    load_chat(8,({"Woman says: Beware of the forest, it is dangerous!\n"}));
    set_level(9); 
    set_ac(2);
    set_wc(5);
    set_al(10); 
    set_race("woman"); 
    set_short("A fluffy cloud woman"); 
    set_long("She stands and looks at you curiously. She is\n" +
              "very friendly and sweet. You notice she is wearing\n" +
              "a plaid dress and a bonnet.\n");
    set_spell_mess1("She gets hostile and beats you with her fists");
    set_spell_mess2("She smacks you hard with her frying pan");
    add_money(50);

   MO(CO(MOBJS+"dress"),TO);
   MO(CO(MOBJS+"bonnet"),TO);

   init_command("wear dress");
   init_command("wear bonnet");

}
}
