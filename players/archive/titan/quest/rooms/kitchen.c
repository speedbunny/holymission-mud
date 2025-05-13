	inherit "room/room";
	object dievca;

	reset(arg) {
	if(!present("cook",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/cooker"),this_object());
}
	if(!present("maid",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/maid"),this_object());
}
	if(!present("lackey",this_object())) {
	move_object(clone_object("players/titan/quest/monsters/lackey"),this_object());
}
	if(!find_living("dievcatko")) {
	dievca=clone_object("players/titan/quest/monsters/girl");
	transfer(dievca,this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Kitchen";
	long_desc = 
		"You have entered to the kitchen. On the walls hang different kitchen's tools.\n"
		"In the centre of kitchen is a big table where cook prepare food. In corner\n"
		"is big iron oven. Near oven is massive wooden cupboard full of kitchen.\n"
		"utensils. From the kitchen you can go to the east, down and up.\n";
	
        items = ({
		"wall","Wall is full of kitchen's tools"
		"walls","Walls are full of kitchen's tools"
		"table","Big oak table"
		"oven","Iron oven where cook cooking food"
		"cupboard","Massive wooden cupboard"
 });
	dest_dir = ({
		"players/titan/quest/rooms/guards","east",
		"players/titan/quest/rooms/cellar","down",
		"players/titan/quest/rooms/tower11","up"});

	property = ({"no_teleport","no_sneak","no_steal"});
}
