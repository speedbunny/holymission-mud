	inherit "obj/treasure";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("silver mirror");
	set_alias("mirror");
	set_short("A silver mirror");
	set_long("Small silver mirror. It is practical thing.\n" +
		"You should show it to someone.\n");
	set_value(150);
	set_weight(1);
}
	init() {
	::init();
	add_action("ukaz","show");
}
	ukaz(str) {
	if(str=="mirror to medusa"&&present("medusa",environment(this_player()))) {
	write("You angrily show mirror against medusa's face.\n");
	say(this_player()->query_name()+" angrily shows mirror against medusa's face.\n");
	shout("Medusa screams in agony.\n");
	call_out("znicenie",1);
	return 1;
}
	if(str=="mirror"||str=="silver mirror") {
	write("You show your silver mirror.\n");
	say(this_player()->query_name()+" shows you his silver mirror.\n");
	return 1;
}
	else {
	notify_fail("Show what ?\n");
	return 0;
}}

	znicenie() {
	object sta,medu;

	medu=present("medusa",environment(this_player()));
	write("Medusa has been changed to stone statue.\n");
	say("Medusa has been changed to stone statue.\n");
	sta=clone_object("players/titan/quest/items/statue");
	destruct(medu);
	move_object(sta,environment(this_player()));
}

