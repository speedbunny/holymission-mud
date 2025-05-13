	inherit"room/room";

	reset(arg) {

	set_light(1);
	short_desc = "On the beach";
	long_desc =
	  "You stand on border of the beach. The beach is in heart of mountains and opens\n"
	+ "to a beautiful scenery. The sea is straight in front of you and sometimes you\n"
	+ "can see foam on top of waves. In distance you can see the outline of an\n" 
	+ "island. Whole beach is covered with yellow sand. There is also a small hut\n"
	+ "which is tucked under high cliff.\n";
 
	smell = "You smell fresh air comming from sea. It is full of salt";
	items =
	      ({"sand","It looks like gold",
		"hut","Small hut with dirty windows",
		"window","Its dirty",
		"sea","Straight blue sea. In distance you see island",
		"door","Strange door without handle and keyhole",
		"island","You see only outlines of island"});
	
	dest_dir =
	      ({"players/titan/quest/rooms/beach1","west",
		"players/titan/quest/rooms/sea2","sea",
		"players/titan/quest/rooms/beach3","southwest"});
}
	init () {
	::init();
	add_action("knock","knock");
	add_action("enter","enter");
	add_action("otvor","open");
}

	enter(str) {
	if(!str) {
	notify_fail("Enter where?\n");
	return 0;
}
	if(str=="hut") {
	write("Bang !!!! You beat into door by your head. Door is closed.\n");
	say(this_player()->query_name()+" beat into door by your head.\n");
	return 1;
}}
	knock(str) {
	if(!str) {
	notify_fail("Knock where ?\n");
	return 0;
}
	if(str=="door") {
	write("Knock Knock Knock\n");
	say(this_player()->query_name()+" knocked on door.\n");
	write("You hear pleasant voice inside of the house: Who is it ?\n");
	write("The door just opened and you see young girl.\n");
	write("She tells you: please come in \n");
	write("You enter the house.\n");
	say(this_player()->query_name()+" entered into hut.\n");
	this_player()->move_player("hut#players/titan/quest/rooms/hut");
	return 1;
}}
	otvor(str) {
	if(str=="door") {
	write("How ?\n");
}
	else {
	notify_fail("Open what ?\n");
}}

