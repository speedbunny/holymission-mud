inherit "room/room";


reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are standing in a clearing in Mythwood.\n"+
              "To the north, a track leads toward a large structure.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/track1","north",
		"players/bobo/krooms/mythwood/clear1","south",
		"players/bobo/krooms/mythwood/clear6","east",
		"players/bobo/krooms/mythwood/clear5","west",
		"players/bobo/krooms/mythwood/clear3","southeast",
		"players/bobo/krooms/mythwood/clear2","southwest",
             });
    items=({
            "building","It's too far away to see something special",
          });
    replace_program("room/room");
}

