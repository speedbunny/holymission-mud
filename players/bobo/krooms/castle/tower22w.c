inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="An exhibition room";
  long_desc="You're on the second floor in an exhibition room.\n";
  dest_dir=({
	"players/bobo/krooms/castle/tower22","east",
   });
/*  move_object(clone_object("players/kelly/monster/"),this_object()); */
}

