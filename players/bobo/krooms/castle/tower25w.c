inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="An exhibition room";
  long_desc="You're on the fifth floor in an exhibition room.\n";
  dest_dir=({
	"players/bobo/krooms/castle/tower25","west",
   });
/*  move_object(clone_object("players/kelly/monster/"),this_object()); */
}

