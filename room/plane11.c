inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="This is a huge, bare, windswept open plain, " +
              "overshadowed by a massive mountain which " +
              "rises up above you to the north.\n";

    dest_dir=({ "room/mount_pass", "north",
                "room/plane13", "east",
                "room/plane6", "south",
                "room/plane12", "west",
             });

    items=({ "mountain", "It really is an immensely large mountain"
          });

    replace_program("room/room");
}

