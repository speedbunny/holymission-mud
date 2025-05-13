inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Ravine";

    long_desc=
              "You are in a ravine between mountains. It seems to\n"+
              "be possible to go up from here.\n";

    dest_dir=({
               "players/bobo/krooms/vill/road7","down",
               "room/mount_top", "up",
             });

    ::reset(arg);
    replace_program("room/room");
}

