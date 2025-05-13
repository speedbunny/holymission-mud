inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You're standing in a clearing in Mythwood.\n"+
              "To the east a path winds through the thick wood.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/clear3","south",
               "players/kelly/rooms/mythwood/clear4","west",
               "players/kelly/rooms/mythwood/mythpath7","east",
               "players/kelly/rooms/mythwood/clear1","southwest",
             });
    ::reset(arg);
    replace_program("room/room");
}

