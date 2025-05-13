inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The ground floor";
  long_desc="You're on the ground floor of the big tower.\n";
  dest_dir=({
	"players/bobo/krooms/castle/corridor2","east",
	"players/bobo/krooms/castle/tower21","up",
   });
}

query_drop_castle() {
    return 1;
}
