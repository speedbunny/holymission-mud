inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n";
  dest_dir=({
	"players/bobo/krooms/castle/cellar8","south",
	"players/bobo/krooms/castle/cellar4","west",
	"players/bobo/krooms/castle/cellar5","southwest",
    "players/kelly/rooms/castle/cellar8","south",
    "players/kelly/rooms/castle/cellar4","west",
   });
}
 
