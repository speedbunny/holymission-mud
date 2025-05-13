inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n";
  dest_dir=({
    "players/kelly/rooms/castle/cellar7","southwest",
    "players/kelly/rooms/castle/cellar9","north",
    "players/kelly/rooms/castle/cellar5","west",
   });
}
 
