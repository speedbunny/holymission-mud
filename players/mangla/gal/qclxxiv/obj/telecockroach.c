inherit "players/qclxxiv/mymonster";

object sender;

query_plural() { return "Telepatic cockroaches"; }

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(5,({
		"ruft.\n",
	  }));
	set_name("Telepatic cockroach");
	set_alias("cockroach");
	set_level(2);
   	set_wc(6);
	set_ac(2);
   	set_hp(66);
	set_sp(15);
   	set_spell_mess1("Telepatic cockroach stingers his opponent.");
   	set_spell_mess2("Telepatic cockroach stingers you.");
	set_chance(8);
	set_spell_dam(5);
    set_al(10);
   	set_aggressive(0);
	set_short("Telepatic cockroach");
	set_long("One of dem famous telepatic cockroaches.\n");
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
	sender->receivecockroach(environment(this_object()));
	return 1;
}
