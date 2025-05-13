	inherit "room/room";
	object po;
	int n;

	reset(arg) {
	if(!present("guard",this_object())) {
	(n=0);
	{
	while(n<2) {
	move_object(clone_object("players/titan/quest/monsters/guard"),this_object());
	(n=n+1);
}}}
	if(!find_living("spevak")) {
	po=clone_object("players/titan/quest/monsters/minstrel");
	transfer(po,this_object());
}
	::reset(arg);
	if(arg) return;

	set_light(1);
	short_desc = "Castle court";
	long_desc = 
		"You entered inside of castle. Now you are standing on open air court.\n"
		+ "High bulwark rises all around you. In corner near entrance to stable\n"
		+ "is big heap of straw. In centre of dark court is deep well. To the west\n"
		+ "is beautiful entrance to throne room. To the north is guard's room.\n";

	dest_dir = ({
		"players/titan/quest/rooms/stable","south",
		"players/titan/quest/rooms/throne","west",
		"players/titan/quest/rooms/guards","north",
		"players/titan/quest/rooms/gate","east"});

	property = ({"no_sneak","no_teleport","no_steal"});

	smell = "It smells straw here.";
	items = ({
		"well","Very deep well",
		"straw","Large heap of dry straw",
		"court","Dark court",
		"bulwark","High bulwark consists by big boulder",
});
}
