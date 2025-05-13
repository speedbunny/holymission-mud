inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n";
  dest_dir=({
    "players/kelly/rooms/castle/cellar2","west",
    "players/kelly/rooms/castle/cellar5","south",
    "players/kelly/rooms/castle/cellar9","east",
    "players/kelly/rooms/castle/cellar3","north",
   });
}
