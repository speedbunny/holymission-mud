inherit "room/room";

reset(arg) {

    set_light(1);
    short_desc="On a broad track";
    long_desc="You're walking along a broad path in Mythwood.\n"+
              "To the north you see a very big building.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/track1","south",
               "players/kelly/rooms/castle/castle_entr","north",
             });
    items=({
            "building","A really extremly enourmous huge building",
          });

    ::reset();
    replace_program("room/room");
}

