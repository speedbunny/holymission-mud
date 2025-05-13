
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("elk");
	load_chat(8,({"The elk nibbles on some grass near a tree.\n"}));
   	set_level(9);
   	set_size(3);
   	set_alias("elk");
   	set_short("A cloud elk");
   	set_long("A great elk stands before you. Its size intimidates\n" +
	    	 "you and it pauses to look at you. He takes a few steps\n" +
		 "towards you in agression. You see his rack and step back.\n");
   	set_spell_mess1("The elk mercilessly tosses you with its antlers");
   	set_spell_mess2("The elk lowers it's head in combat");
        add_money(100);
  }
}
