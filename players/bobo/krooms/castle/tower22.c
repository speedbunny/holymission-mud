inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The second floor";
  long_desc="You're on the second floor of the big tower.\n"+
      "To the west there's a room.\n";
  dest_dir=({
	"players/bobo/krooms/castle/tower22w","west",
	"players/bobo/krooms/castle/tower23","up",
	"players/bobo/krooms/castle/tower21","down",
   });
}

