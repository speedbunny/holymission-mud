inherit "room/room";

reset(arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levelb/room8", "east", });
  short_desc = "Empty room";
  long_desc = "A small empty room.\n";

replace_program("room/room");
}
