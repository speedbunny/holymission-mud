inherit "room/room";


reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You're standing on a clearing in Mythwood.\n"+
              "To the south the forest is thicker.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath4","south",
               "players/kelly/rooms/mythwood/clear2","west",
               "players/kelly/rooms/mythwood/clear4","north",
               "players/kelly/rooms/mythwood/clear3","east",
               "players/kelly/rooms/mythwood/clear5","northwest",
               "players/kelly/rooms/mythwood/clear6","northeast",
             });
    replace_program("room/room");
}

