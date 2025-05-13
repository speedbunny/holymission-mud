inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The ground floor";
  long_desc="You're on the ground floor of the big tower.\n";
  dest_dir=({
    "players/kelly/rooms/castle/tower21","up",
    "players/kelly/rooms/castle/corridor2","east",
   });
}

query_drop_castle() {
    return 1;
}
