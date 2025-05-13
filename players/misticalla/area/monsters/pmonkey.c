
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("purple ape");
    set_alias("ape");
    set_level(11); 
    set_ac(4);
    set_wc(7);
    set_al(20); 
    set_race("animal"); 
    set_short("A huge purple ape"); 
    set_long("You see a giant purple ape, he looks much like\n" +
              "the cartoon character Grape Ape. He is kind of\n" +
	      "cute cute and friendly.\n");
    set_spell_mess1("I'm grape ape....woowooo");
    set_spell_mess2("Gimme banana..");
    add_money(100);
}
}
