inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "room4";
  long_desc = 
        "This room is full of smoke.\n"
        "It is almost impossible to breathe in here.\n";
  dest_dir = ({ "players/jake/2halla","east" });
  clone_list = ({ 1, 1, "smoke", "players/jake/monster/smoke", 0 });

::reset();
replace_program("room/room");
}

