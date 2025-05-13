inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The first floor";
  long_desc="You're on the first floor of the big tower.\n"+
      "To the west there's a room.\n";
  dest_dir=({
    "players/kelly/rooms/castle/tower22","up",
    "players/kelly/rooms/castle/tower20","down",
    "players/kelly/rooms/castle/tower21w","west",
    "players/kelly/rooms/castle/tower21bureau.970915.c","east",
   });
}

