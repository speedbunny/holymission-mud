inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="You are standing at the northeastern edge of a large, " +
              "windswept open plain. To the south and west you can " +
              "see the rolling grasses stretch out. To the east it " +
              "seems someone has set up a nice " +
              "little shop to the east here. Maybe you should enter " +
              "and see what they sell...\n";

    dest_dir=({
               "/players/sargon/obj/shop","east",
               "room/ruin", "south",
               "room/plane6", "west" });

    items=({
            "plains","Stretching out the west and south",
            "plain","Stretching out the west and south",
          });

    ::reset(arg);
    replace_program("room/room");

}


