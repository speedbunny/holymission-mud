
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("moose");
   	set_level(12);
   	set_size(3);
   	set_alias("moose");
   	set_short("A large brown moose");
   	set_long("It is huge and looks at you curiously.\n" +
	    	 "The moose has large furry antlers that\n" +
		 "would really hurt if you attacked it!\n");
   	set_spell_mess1("The moose tosses you with its antlers");
   	set_spell_mess2("The moose grunts and charges at you");
        add_money(100);
  }
}
