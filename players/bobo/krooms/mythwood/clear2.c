inherit "room/room";

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You're standing in a clearing in the heart of Mythwood.\n"+
              "From the thick forest surrounding you, eyes are stare out.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/clear5","north",
		"players/bobo/krooms/mythwood/clear1","east",
		"players/bobo/krooms/mythwood/clear4","northeast",
             });
    items=({
            "eyes","You don't dare to take a closer look",
          });
}

