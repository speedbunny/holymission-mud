inherit "room/room";


reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You're standing on a clearing in Mythwood.\n"+
              "To the south the forest is thicker.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/clear4","north",
		"players/bobo/krooms/mythwood/mythpath4","south",
		"players/bobo/krooms/mythwood/clear3","east",
		"players/bobo/krooms/mythwood/clear2","west",
		"players/bobo/krooms/mythwood/clear5","northwest",
		"players/bobo/krooms/mythwood/clear6","northeast",
             });
    replace_program("room/room");
}

