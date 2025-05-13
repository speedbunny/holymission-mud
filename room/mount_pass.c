inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Mountain pass";

    long_desc = "The path north leads through a long straight ravine " +
                "where you can just make out sunlight on the other " +
                "end. Here there have been some rock slides and a " +
                "hole has opened in the ground leading down into " +
                "a series of caves or mines. To the south it opens " +
                "into a large plain.\n";

    dest_dir=({
                "players/haplo/ravine/ravine1", "north",
                "room/mine/tunnel", "down",
                "room/plane11", "south",
             });

    items=({ "path", "A narrow mountain path",
             "pass", "A steep mountain pass, promising a beautiful view ahead",
             "landslide", "The path is completely blocked by a large " +
                          "landslide ahead",

             "tunnel", "It looks dark in there",
             "tunnel entrance", "It looks dark in there",
             "entrance", "It looks dark in there",
          });

    ::reset(arg);
    replace_program("room/room");
}

