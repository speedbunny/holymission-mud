inherit "room/room";


void reset(int arg) {

    set_light(1);
    short_desc = "Faun village";
    long_desc="You are standing in a village inhabited of fauns.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/faun_mark1","east",
		"players/bobo/krooms/mythwood/mythpath7","west",
             });
    ::reset();
    replace_program("room/room");
}

