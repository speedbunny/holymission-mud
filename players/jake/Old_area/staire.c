inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "staire";
  long_desc = 
        "You have entered the basement.\n"
        "It is very gloomy down here.\n";
  dest_dir = ({ "players/jake/stairj.c", "up",
        "players/jake/basej", "south" });

replace_program("room/room");
}


