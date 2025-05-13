
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("Cloud Boy");
    set_alias("boy");
    load_chat(8,({"Boy screams: This place is not for mortals, cloud " +
                  "people are the only ones\n" +
                  "allowed!  LEAVE!\n"}));
    set_level(11); 
    set_ac(3);
    set_wc(6);
    set_al(-10); 
    set_race("man"); 
    set_short("A mean cloud boy"); 
    set_long("An agressive cloud boy. His name is Brian McCloud.\n" +
              "He is about your age, and is very mean looking.\n");
    set_spell_mess1("Cloud boy kicks you in the knees");
    set_spell_mess2("He screams and yells then kicks you");
    add_money(80);
}
}
