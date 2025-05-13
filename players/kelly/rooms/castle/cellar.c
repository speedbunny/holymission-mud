inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n"+
   "Stairs lead upwards.\n";
  dest_dir=({
    "players/kelly/rooms/castle/cellar_top","up",
    "players/kelly/rooms/castle/cellar2","north",
    "players/kelly/rooms/castle/cellar1","west",
    "players/kelly/rooms/castle/cellar6","south",
   });
}
 
