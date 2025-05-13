inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The third floor";
  long_desc="You're on the third floor of the big tower.\n"+
      "To the west there's a room.\n";
  dest_dir=({
	"players/bobo/krooms/castle/tower23w","west",
	"players/bobo/krooms/castle/tower24","up",
	"players/bobo/krooms/castle/tower22","down",
   });
}

