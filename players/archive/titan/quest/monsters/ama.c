	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(!arg) {
	set_name("ama");
	set_race("human");
	set_gender(2);
	set_alias("hunter");
	set_al(200);
	set_level(10);
	set_short("A ama");
	set_long("Young hunter of pearl. She is beautiful with very pleasant voice.\n"
		+ "She know all about pearls hunting and picking. If you dont believe then you\n"
		+ "try ask about pearls hunting and picking.\n");
}}
	init() {
	add_action("ask","ask");
	add_action("fuck","fuck");
}
	fuck(str) {
	if(!str) {
	notify_fail("Fuck yourself ?\n");
	return 0;
}
	if(str=="ama") {
	write("You try rape Ama, but she kickde you into the balls.\n\n");
	write("You are screaming Auuuuu !!!!\n\n");
	say(this_player()->query_name()+" tries rape Ama, but Ama kicked "+this_player()->query_name()+" into the balls.\n\n");
	return 1;
}}
	ask(str) {
	if(str=="about pearls hunting and picking") {
	write("Ama comfortable sits on chair and begin long speech about pearls\n");
	write("hunting and picking. She explained you all what must know pearl hunter.\n");
	write("After long time of Ama's speech, she finaly proclaimed: I hope that you \n");
	write("find many pearls. Good luck.\n");
	move_object(clone_object("players/titan/quest/items/nothing"),this_player());
	return 1;
}
	else
	return 0;
}
