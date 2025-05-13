inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In the cellar";
  long_desc="You're in the cellar of the castle.\n"+
   "Stairs lead upwards.\n";
  dest_dir=({
	"players/bobo/krooms/castle/castle_yard","up",
   });
}
 
query_drop_castle() {
    return 1;
}
