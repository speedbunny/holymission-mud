inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="Little life can be seen this huge open plain, " +
              "merely scrub vegetation and the occasional small " +
              "furry animal. To the east lie the remains of " +
              "an old building.\n";

    dest_dir=({ "room/plane6", "north",
                "room/ruin", "east",
                "room/plane2", "south",
                "room/plane7", "west",
             });

    items=({ "vegetation", "Only scrub vegetation grows on " +
                           "this huge open plain",
             "remains", "There is a crumbling old ruin to the east",
             "building", "There is a crumbling old ruin to the east",
          });

    replace_program("room/room");

}
