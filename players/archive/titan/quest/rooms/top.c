	inherit "room/room";
	int counter;

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "In front of castle";
	long_desc =
		  "You are standing in front of a castle. Near you is a deep moat that is\n"
		+ "full of a strange liquid which surrounds castle of all sides. Behind the\n"
		+ "moat rises the high castle walls. In front of you is a massive castle gate\n"
		+ "with drawbridge. There are high bulwark towers on both sides of the castle.\n"
		+ "Near you is a deep abbys, on the bottom which you see foam of the strong surf.\n"
;

	dest_dir = ({
		"players/titan/quest/rooms/middle","down"
});

	smell = "Fresh air comes from mountains";
	items = ({
		"moat","Deep moat full of strange liquid",
		"castle","This is famous castle of Hogan. Is the seat of king Vladimir",
		"bulwark","Dark bulwark",
		"gate","Massive gate",
		"drawbridge","Drawbridge is mades of rough trunks",
		"towers","High towers with loopholes",
		"tower","High tower with loopholes",
		"liquid","Strange dark liquid",
		"abyss","You are looking into deep abyss",
		"surf","Strong surf beat into high cliff"
});
}

	init() {
	::init();
	add_action("enter","enter");
	add_action("wave","wave");
	add_action("knock","knock");
}

	wave(str) {
	counter=1;
	if(str=="with linnen"&&present("linnen",this_player())) {
	write("You hear some voice from castle: OK !! OPEN GATE !!\n");
	write("Crack Crack Crack Crack\n");
	write("Drawbridge is slowly going down.\n");
	write("Gate is now opened.\n");
	counter=2;
	say("Drawbridge is slowly going down.\n");
	say("Gate is now opened.\n");
	return 1;
}}
	enter(str) {
	if(!str) {
	notify_fail("Enter where ?\n");
	return 0;
}
	if(str=="castle"||str=="gate"&&counter>1) {
	write("You enter into castle.\n");
	write("Drawbridge is slowly going up.\n");
	say(this_player()->query_name()+" enters to castle.\n");
	this_player()->move_player("enter#players/titan/quest/rooms/gate");
	counter=1;
	return 1;
}
	else {
	notify_fail("Drawbridge is draw up.\n");
	return 0;
}}
	knock(str) {
	write("Do you normal. You want knock across moat.\n");
	return 1;
}
