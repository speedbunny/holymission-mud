	inherit "room/room";
        int counter;

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Quarry";
	long_desc =
		  "This is an old long time unused quarry. A long time ago this quarry was\n"
		+ "an eventful place, but when supply of marble was exhausted, the quarry\n"
		+ "closed. Now it is only a monument to the old times. You should be\n"
		+ "very careful, because there are boulders that rolls down and may hurt you.\n" 
		+ "Everywhere around you are big boulders.\n";

	smell = "You smell musty air";
	items = ({
		"boulder","Big boulder covered with moss. It appears to be loosen",
		"boulders","Everywhere around you are many boulders",
		"slopes","Steep slopes"});

	dest_dir = ({
		"players/titan/quest/rooms/ravine4","east"
});
}
	init() {
	::init();
	add_action("manage","move");
	add_action("tear","tear");
	add_action("zober","get");
	add_action("pozri","look");
}
	manage(str) {
	counter=1;
	if(str=="boulder") {
	write("Hej rup !! Hej rup !! Hej rup !!\n\n");
	write("You moved boulder and you see piece of linnen under moved boulder.\n\n");
	counter=2;
	return 1;
}
	else {
	notify_fail("Move what ?\n");
	return 0;
}}
	tear(str) {
	if(str=="linnen"&&counter>1) {
	write("You have teared small piece of linnen.\n");
	move_object(clone_object("players/titan/quest/items/linnen"),this_player());
	counter=0;
	return 1;
}}
	zober(str) {
	if(str=="linnen") {
	write("Linnen is under heavy boulder.\n");
	return 1;
}
	else {
	notify_fail("get what ?");
	return 0;
}}

	pozri(str) {
	if(str=="at linnen"&&counter>1) {
	write("You see small piece of linnen under heavy boulder.\n");
	say(this_player()->quary_name()+" looks at linnen.\n");
	return 1;
}
}
