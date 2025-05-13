inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "room2";
  long_desc = 
        "This room looks like nobody has entered it in years.\n"
        "Looking at the condition, it makes you wonder why you are here.\n";
  dest_dir = ({ "players/jake/2hall", "east" });

replace_program("room/room");
}


