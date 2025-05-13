inherit "room/room";

object mag_stone;

reset(arg) {
    if(!arg) {
	short_desc="Black room";
	long_desc="This is the black room. It looks rather dark and smelly in here.\n";
	smell="There's a definite smell of decaying garbage.";
	property=({ "no_teleport" });
        dest_dir=({
            "room/sub/door_trap", "east",
                 });
    }
    extra_reset();
}

init() {
    ::init();
    add_action("east","east");
}

east() {
    if (!"room/sub/door_trap"->query_west_door()) {
	write("The door is closed.\n");
	return 1;
    } else return ::move();
}

extra_reset() {
    object black_stone;
    object rat;
    int i;
    if(present("rat")) return;
    if(!present("bottle")) move_object(clone_object("obj/beer"), this_object());
    for(i=0;i<5;i++) {
	rat = clone_object("obj/monster");
	rat->set_name("rat");
	rat->set_alias("black rat");
	rat->set_level(6);
        rat->set_size(1);
	rat->set_short("An ugly black rat");
	rat->set_wc(12);
	rat->set_aggressive(1);
	move_object(rat, this_object());
	if(!mag_stone) {
	    mag_stone=clone_object("obj/mag_stone");
	    move_object(mag_stone, rat);
	}
	else {
	    black_stone = clone_object("obj/treasure");
	    black_stone->set_id("stone");
	    black_stone->set_alias("black stone");
	    black_stone->set_short("A black stone");
	    black_stone->set_value(60);
	    move_object(black_stone, rat);
	}
    }
}
