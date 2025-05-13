inherit "room/room";

reset(arg){
  set_light (0);
  dest_dir = ({"players/airborne/temple/levelb/room5", "east", });
  short_desc = "Empty room";
  long_desc =
"This small room looks like it was once used as a private speaking chamber. "
"Doesn't look like anyone has been here for centuries.\n";

replace_program("room/room");
}
