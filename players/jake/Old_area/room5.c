inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "room5";
  long_desc = 
        "This is Charlie's room.\n"
        "He has his own room for a reason.  Because he doesn't like people.\n"
        "Please leave.\n";
  dest_dir = ({ "players/jake/2hallc", "east" });
  clone_list = ({ 1, 1, "charlie", "players/jake/monster/charlie", 0 });

::reset();
replace_program("room/room");
}


