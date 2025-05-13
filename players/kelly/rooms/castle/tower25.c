inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The fifth floor";
  long_desc="You're on the fifth floor of the big tower.\n"+
      "To the west there's a room.\n";
  dest_dir=({
    /* "players/kelly/rooms/tower26","up", */
    "players/kelly/rooms/castle/tower24","down",
    "players/kelly/rooms/castle/tower25w","west",
   });
}
