inherit "room/room";


void reset(int arg) {

    set_light(1);
    short_desc="A broad track";
    long_desc="This is a broad track through Mythwood.\n"+
              "Trees line the way.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/track2","north",
		"players/bobo/krooms/mythwood/clear4","south",
               "players/kelly/rooms/mythwood/track2","north",
             });
    ::reset();
    replace_program("room/room");
}

