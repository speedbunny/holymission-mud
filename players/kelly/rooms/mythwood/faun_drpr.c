inherit "room/room";

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="The Faun-druid's private room";
    long_desc="You are in the Faun-druid's private room.\n"+
              "A bed, some bookshelves and a table are standing here.\n";

    dest_dir = ({
                 "players/kelly/rooms/mythwood/faun_druid","west",
               });
    items=({
            "bed","An ordinary bed. Nothing to wonder about",
            "shelves","The bookshelves contain various book "+
                      "about magics, healing properties etc",
            "table","A wooden table",
          });
}

