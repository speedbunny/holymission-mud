inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n";
  dest_dir=({
	"players/bobo/krooms/castle/cellar6","west",
	"players/bobo/krooms/castle/cellar8","northeast",
   });
}
 
