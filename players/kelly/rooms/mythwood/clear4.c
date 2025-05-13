inherit "room/room";


reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are standing in a clearing in Mythwood.\n"+
              "To the north, a track leads toward a large structure.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/clear1","south",
               "players/kelly/rooms/mythwood/clear5","west",
               "players/kelly/rooms/mythwood/clear6","east",
               "players/kelly/rooms/mythwood/track1","north",
               "players/kelly/rooms/mythwood/clear2","southwest",
               "players/kelly/rooms/mythwood/clear3","southeast",
             });
    items=({
            "building","It's too far away to see something special",
          });
    replace_program("room/room");
}

