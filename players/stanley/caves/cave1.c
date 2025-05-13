inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc="Inside cave";
  long_desc=
    "You are standing just inside the entrance to a dark, forboding\n"
    "cave. You stand a moment in indecision, trying to decide whether\n"
    "you really want to proceed furthur inside.\n"+
    " ";
  dest_dir=({
    "/players/stanley/caves/entrance","out",
  });
}
