inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n"+
              "To the north the wood lighten into a clearing.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/clear1","north",
		"players/bobo/krooms/mthwood/mythpath","south",
             });
    ::reset();
    replace_program("room/room");
}

