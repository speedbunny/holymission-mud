inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "floor3";
  long_desc = 
        "Ok, You got away from hogatha.\n"
        "That's good, but do you think HE is glad to see you?\n";
  dest_dir = ({ "players/jake/halla.c", "east" });
  clone_list = ({ 1, 1, "dumb", "players/jake/monster/dumb", 0 });

::reset();
replace_program("room/room");
}

