inherit "room/room";

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc = "A small storage room";
    no_castle_flag = 1;
    long_desc = 
	"You are in a small and dusty storage room.\n" +
	    "You can see the shop through the opening to the east.\n";
    dest_dir = ({"room/main_shop", "east"});
}

init(arg)
{
	object	ob;
	int	does_exist;
/*
	if(this_player()) {
		if(
			!present("tech_quicktyper", this_player())
			&&
			!present("tech_quicktyper", this_object())
		) {
			ob = clone_object("obj/quicktyper");
			move_object(ob, this_object());
		}
	}
*/
	::init(arg);
}

