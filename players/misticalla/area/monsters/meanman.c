
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("cloud man");
    set_alias("man");
    load_chat(8,({"Man says: Get out of here!  You will surely parish!\n"}));
    set_level(11); 
    set_ac(3);
    set_wc(6);
    set_al(-10); 
    set_race("man"); 
    set_short("A mean cloud man"); 
    set_long("An agressive cloud man, he doesn't like your\n" +
              "intrusion in his world - The land of the cloud\n" +
	      "people.\n");
    set_spell_mess1("I don't want your kind here..");
    set_spell_mess2("Go on, get out of here");
    add_money(80);
}

}
