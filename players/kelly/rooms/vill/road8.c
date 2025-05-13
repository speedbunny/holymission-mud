inherit "room/room";

reset(arg) {

    set_light(1);
    short_desc="A road outside of a village";
    long_desc="You are on a road leading north through a strange "+
              "forest. You can see a rock to the south.\n";
    dest_dir=({
               "players/kelly/rooms/vill/woodroad","north",
               "players/kelly/rooms/vill/road5","south",
             });
    items=({
            "forest","A strange feeling comes over you as you look at the forest",
            "rock","A big red rock to the south",
          });

    ::reset();
    replace_program("room/room");
}


