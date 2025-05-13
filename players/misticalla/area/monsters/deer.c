
inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("deer");
   	set_level(7);
	set_size(2);
   	set_alias("deer");
   	set_short("A shy little deer");
   	set_long("It looks at you curiously with big eyes.\n" +
		 "It is nibbling on some grass beneath a tree.\n");

	load_chat(9,({
		"The deer grazes in your direction curiously.\n"}));

   	set_spell_mess1("The deer runs at you full force");
   	set_spell_mess2("It looks at you innocently and tries to run");

        add_money(60);
  }
}
