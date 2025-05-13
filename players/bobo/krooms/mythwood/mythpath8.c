inherit "room/room";

reset(arg) {

    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking along a path in Mythwood.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/mythpath3","north",
		"players/bobo/krooms/vill/woodroad","south",
             });
    ::reset();
    replace_program("room/room");
}


