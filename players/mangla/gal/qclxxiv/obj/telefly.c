inherit "players/qclxxiv/mymonster";

object sender;

query_plural() { return "Telepatic flies"; }

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(15,({
		"bzzzzzzz.\n",
		"bzzzzz bzzz.\n",
		"bzzzz.\n",
		"bzzzzzz.\n",  /* <<< maybe , is essential*/
	  }));
	 load_a_chat(15,({
		"BZZZZ.\n",
		"BZZZZZZ.\n",
		"Telepatic fly tries to stinger you.\n",
		"Telepatic fly drops fly shit on your head.\n",  
	  }));
	set_name("Telepatic fly");
	set_alias("fly");
	set_level(2);
   	set_wc(6);
	set_ac(2);
   	set_hp(66);
	set_sp(15);
   	set_spell_mess1("Telepatic fly stingers his opponent.");
   	set_spell_mess2("Telepatic fly stingers you.");
	set_chance(8);
	set_spell_dam(5);
    set_al(10);
   	set_aggressive(0);
	set_short("Telepatic fly");
	set_long("One of dem famous telepatic flies.\n");
	enable_commands();
}

set_sender(arg) { sender = arg; } /* pointer to the BOX that is! */

go_check(arg)
{
	if (!sender) {
		say("No sender has been specified!\n");
		write("No sender has been specified!\n");
		return 1;
	}
	init_command(arg); 
	sender->receivefly(environment(this_object()));
	return 1;
}
