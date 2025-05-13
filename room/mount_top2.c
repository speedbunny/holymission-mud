inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Plateau";

    long_desc=
              "You are on a large, open plateau on top of the " +
              "mountain. The view is fantastic in all directions " +
              "and the clouds that rush past above feels so close " +
              "you could almost touch them. The air here is fresh " +
              "and clean. To your north you can see the Magetower " +
              "reach up to the clouds.\n";

    dest_dir=({
               "room/mount_top", "west",
		"players/saffrin/area/tower/room/oldstart", "north",
             });

    ::reset(arg);
    replace_program("room/room");
}
