	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("medusa");
	set_alias("meduza");
	set_level(50);
	set_size(3);
	set_gender(2);
	set_race("fish");
	set_has_gills();
	set_al(-1000);
	add_money(5000);
/*	set_no_sneak(); */
	set_short("Strange medusa");
	set_long("");
/* we dont need long description */
	load_chat(15,({
		"Medusa stares to nowhere.\n",
		"Medusa says: I will be your last judge.\n",
		"Medusa shouts: Go away or fight !\n",
		"Medusa say: I hate people !\n",
		"Medusa yawns sleeply.\n"
}));
}

	attack() {
	int i;
	object utocnik;
	utocnik=this_player()->query_attack();

	if(::attack()) {
	i=random(200);
		if(i<21) {
		write("Medusa looks at you with sight fulls of hate.\n");
		write("Strange force transported you to unknown place.\n");
		say("Medusa looks at "+utocnik->query_name()+" sight full of hate.\n");
		say(utocnik->query_name()+" has been transported by Medusa.\n");
                move_object(clone_object("players/titan/quest/items/medusa_thing"),utocnik);

		if(i>14) {
		utocnik->move_player("ravine1#/players/titan/quest/ravine1");
}
		if(i>9 && i<15) {
		utocnik->move_player("church#/room/church");
}
		if(i>4 && i<10) {
		utocnik->move_player("post#/room/post");
}
		if(i<5) {
		utocnik->move_player("quarry#/players/titan/quest/rooms/quarry");
}}
		if(i<51 && i>20) {
		say("Medusa hits "+utocnik->query_name()+" with poisoned tentacle.\n");
		write("Medusa hits you with poisoned tentacle.\n");
		utocnik->add_poison(5);
}}
	return 1;
} 
        init() {
	::init();
	add_action("hold","hold");
	add_action("fear","fear");
	add_action("odplas","suggest fear");
	add_action("pozri","look");
	add_action("block","block");
}
	hold(str) {
	if(str=="medusa"||str=="meduza") {
	write("Medusa smiles at your painful hold.\n");
	return 1;
}
	else {
	notify_fail("Hold whom ?\n");
	return 0;
}}
	fear(str) {
	if(str=="medusa"||str=="meduza") {
	write("Medusa laughs demonicaly at your useless experiment.\n");
	return 1;
}
	else {
	notify_fail("Fear whom ?\n");
	return 0;
}}
	odplas(str) {
	if(str=="medusa"||str=="meduza") {
	write("Medusa laughs demonicaly at your useless experiment.\n");
	return 1;
}
	else {
	notify_fail("Suggest fear whom ?\n");
	return 0;
}}
	pozri(str) {
	if(str=="at medusa"||str=="at meduza") {
	write("You see only eyes fulls of hate.\n");
	write("You have been transported to unknown place.\n");
	say(this_player()->query_name()+" looks at Medusa and disappears.\n");
	this_player()->move_player("church#/room/church");
	move_object(clone_object("players/titan/quest/items/medusa_thing"),this_player());
	return 1;
}
	else {
	notify_fail("Look at whom ?\n");
	return 0;
}}
	block(str) {
	if(str=="medusa"||str=="meduza") {
	write("Medusa laughs at your stupid block.\n");
	return 1;
}
	else {
	notify_fail("Block whom ?\n");
	return 0;
}} 
		
