inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A cross-vault";
  long_desc="You're standing on a cross-vaulting.\n";
  dest_dir=({
    "players/kelly/rooms/castle/castle_yard","north",
    "players/kelly/rooms/castle/corridor1","south",
    "players/kelly/rooms/castle/tower20","west",
    "players/kelly/rooms/castle/cellar_top","east",
   });
}

