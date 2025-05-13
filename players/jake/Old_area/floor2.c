inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "floor2";
  long_desc = 
        "It looks like there has been a fire in here recently.\n"
        "Everything is charred black.\n"
        "There is even a small fire burning in the corner.\n";
  dest_dir = ({ "players/jake/hallk.c","east" });
  clone_list = ({ 1, 1, "spirit", "players/jake/monster/firespirit", 0 });

::reset();
replace_program("room/room");
}

