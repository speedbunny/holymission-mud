inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "path4";
  long_desc = 
        "You are still travelling on the dirt path.\n"
        "You see a large building to your north.\n"
        "There is a small dog wandering around here.\n";
  dest_dir = ({ "players/jake/path5.c", "north",
        "players/jake/path3","south" });
  clone_list = ({ 1, 1, "dog", "players/jake/monster/dog", 0 });

::reset();
replace_program("room/room");
}

