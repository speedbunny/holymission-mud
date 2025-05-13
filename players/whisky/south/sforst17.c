inherit "room/room";

reset(started) {
    if (started) return;
    set_light(1);
    short_desc="A dimly lit forest";
    long_desc="You are in part of a huge, dimly lit forest.\n"
	+ "Trails lead north and west and a path leads south.\n";
    dest_dir=({ "room/south/sforst16","north",
                "room/south/sforst18","west",
                "players/herp/abbey/i01","south" });
}
