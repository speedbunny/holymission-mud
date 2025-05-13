inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The race-soul room";
    no_castle_flag = 0;
    long_desc = 
        "This is a little dusky room. There is a strange feeling in the air.\n"
        + "In the middle of the room is a strange magical symbol. I think you\n"
        + "should enter it to become that for what you entered this room.\n";
    dest_dir = 
        ({
        "/players/jug/castle.c", "west",
        });
    items =
        ({
        "symbol", "This is a magical symbol, enter it to set your race",
        });
}

init() {
	::init();
	add_action("get_exsoul", "getsoul");
	add_action("enter_symbol", "enter");
}

query_light() {
    return 1;
}

enter_symbol(str) {
	object ob;
	
	if (!str) {
		write("Enter what !?\n");
		return 1;
		}
	if (str != "symbol") {
		write("That is not here !\n");
		return 1;
		}
	if (present("race-soul", this_player())) {
		write ("Your race-soul gets new energy as you enter the symbol,\n");
		return 1;
		}
	write("Suddenly there is lightning sphere in the air. With a tingle the\n");
	write("sphere begins to move in your direction and enters in your\n");
	write("chest and you feel a warm feeling going throw your body.\n");
	ob = clone_object("/players/jug/obj/racesoul");
	move_object(ob,this_player());
	call_other(ob, "set_race");
	return 1;
}

get_exsoul() {
	object ob;

        ob = clone_object("tools/exsoul/exsoul");
	transfer(ob, this_player());
	return 1;
}
