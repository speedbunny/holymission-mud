
inherit "obj/monster"; 

#include "/players/misticalla/defs.h"
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("friendly Cloud Boy");
    set_alias("boy");
    load_chat(8,({"Boy says: Hi, I'm Tommy McCloud, who are you?\n"}));
    set_level(5); 
    set_ac(2);
    set_wc(3);
    set_al(10); 
    set_race("boy"); 
    set_short("A fluffy cloud boy"); 
    set_long("He is a strange looking cloud child, I think he\n" +
              "wants you to play with him. You notice he is\n" +
              "wearing a cap that nearly covers his cloudy eyes.\n");
    set_spell_mess1("Cloud boy hits you with his fists");
    set_spell_mess2("Cloud boy throws down his cap and kicks you");
    add_money(25);

   MO(CO(MOBJS+"cap2"),TO); 
 
   init_command("wear cap");

}
}
