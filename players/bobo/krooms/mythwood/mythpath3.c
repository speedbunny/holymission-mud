inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/mythpath8","south",
//		"players/bobo/krooms/mythwood/mythpath6","east",
		"players/bobo/krooms/mythwood/mythpath","west",
             });

    ::reset();
    replace_program("room/room");
}

