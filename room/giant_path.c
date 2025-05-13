inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A path";

    long_desc=
              "You are on a path going in east/west direction.\n" +
              "There are some VERY big footsteps here.\n";

    dest_dir=({
               "room/big_tree", "east",
               "room/giant_lair", "west",
             });

    replace_program("room/room");
}
