inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n"+
   "Stairs lead upwards.\n";
  dest_dir=({
	"players/bobo/krooms/castle/cellar2","north",
	"players/bobo/krooms/castle/cellar6","south",
	"players/bobo/krooms/castle/cellar1","west",
	"players/bobo/krooms/castle/cellar_top","up",
   });
}
 
