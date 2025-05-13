	inherit "obj/weapon";

	reset(arg) {
	::reset(arg);
	set_name("teeth");
	set_alias("teeth");
	set_id("Huge teeth");
	set_short("Huge teeth");
	set_long("You see huge shark's teeth. Hmmmm. You think that teeth is good weapon.\n");
	set_weight(4);
	set_value(2999);
	set_hit_func(this_object());
}
	weapon_hit(attacker) {
	write("You bite with teeth into "+attacker->query_name()+"'s head.\n");
	say(this_player()->query_name()+" bites "+attacker->query_name()+" into the head.\n");
	return random(35);
}
