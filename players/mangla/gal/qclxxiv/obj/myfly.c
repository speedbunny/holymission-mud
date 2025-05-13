inherit "players/qclxxiv/mymonster";

object sender;
object followed;
string prefix;

query_plural() { return "Telepatic flies"; }

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	set_prefix("=");
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
	set_short(0);
	set_long(0);
    load_match(this_object(), ({ 
								"send", ({"a","e","n","s","i","d","t","m",
										"b","o","f","r","h","p","k","l","y",
										"c","j","q","g","u","v","w","x","z",}),
								}) );
	set_living_name("ifly");
	set_heart_beat(1);
	enable_commands();
}

set_sender(arg) { sender = arg; } /* pointer to the BOX that is! */
set_followed(arg) { 
	followed = arg; 
	set_heart_beat(1);
} /* pointer to the target that is! */

set_prefix(arg) { prefix = arg; }

self_dest() { destruct(this_object()); }

send(arg) {
	if (sender && environment(sender) && living(environment(sender))) {
		tell_object(environment(sender),prefix+arg);
	}
	return 1;
}

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

heart_beat() {
	if (followed && (environment(this_object())!=environment(followed))) {
		move_object(this_object(),environment(followed) );
		if (sender) sender->receivefly(environment(this_object()));
	}
	::heart_beat();
	set_heart_beat(1);
}
