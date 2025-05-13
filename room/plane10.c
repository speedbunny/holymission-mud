inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="A large open plain stretches off to the north, " +
              "east and south, while a thick, impenetrable " +
              "forest blocks any exit to the west.\n";

    dest_dir=({ "room/plane12", "north",
                "room/plane6", "east",
                "room/plane7", "south",
             });

    items=({ "forest", "It's so thick that it's completely impenetrable",
          });

    ::reset(arg);
    replace_program("room/room");
}

