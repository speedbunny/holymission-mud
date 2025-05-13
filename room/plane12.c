inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="Here, the plains are bordered by a large " +
              "mountain to the north, which looms up over " +
              "you, cutting off the sunshine. To the west, " +
              "you can see the beginnings of a forest.\n";

    dest_dir=({ "room/plane11", "east",
                "room/plane10", "south",
                "room/deep_forest1", "west",
             });

    items=({ "mountain", "A large mountain rears up above you; " +
                         "it is far too steep to climb",
             "forest", "There is a forest to the west. " +
                       "It looks as if it is very thick",
          });

    ::reset(arg);
    replace_program("room/room");
}

