inherit "room/room";


void reset(int arg) {

    set_light(1);
    short_desc = "Faun village";
    long_desc="You are standing in a village inhabited of fauns.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath7","west",
               "players/kelly/rooms/mythwood/faun_mark1","east",
             });
    ::reset();
    replace_program("room/room");
}

