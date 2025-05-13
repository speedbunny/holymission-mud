
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("Cloud Girl");
    set_alias("girl");
    load_chat(8,({"Girl says: I'm telling my mommy you are here!\n"}));
    set_level(6); 
    set_ac(2);
    set_wc(3);
    set_al(-10); 
    set_race("girl"); 
    set_short("A mean cloud girl"); 
    set_long("An agressive cloud girl. Her name is Gina McCloud.\n" +
              "She is about your age, and is very mean looking.\n");
    set_spell_mess1("Gina hits you with her dolls");
    set_spell_mess2("Gina yells for her mother and then kicks you");
    add_money(80);
}

}
