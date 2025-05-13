inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Top of the stairs";
  long_desc="You're at the top of the stairs to the cellar.\n"+
   "The cellar seems to be wet and cold.\n";
  dest_dir=({
	"players/bobo/krooms/castle/corridor2","west",
	"players/bobo/krooms/castle/cellar","down",
   });
}
 
