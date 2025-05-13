
inherit "obj/monster"; 

#include "/players/misticalla/defs.h"
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("Friendly Cloud Girl");
    set_alias("girl");
    load_chat(8,({"Girl says: Will you play with me?  I like to play!\n"}));
    set_level(5); 
    set_ac(2);
    set_wc(3);
    set_al(10); 
    set_race("human"); 
    set_short("A fluffy cloud girl"); 
    set_long("She is a strange looking cloud child, I think she\n" +
              "wants you to play with her. Her name is Muffy McCloud.\n" +
	      "You notice she is wearing a little bonnet.\n");
    set_spell_mess1("Cloud girl pummels your chest with her fists");
    set_spell_mess2("Cloud girl hates fighting, but kicks your shin");
    add_money(25);

   MO(CO(MOBJS+"bonnet"),TO); 
 
   init_command("wear bonnet");

}
}
