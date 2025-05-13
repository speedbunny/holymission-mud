inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="An exhibition room";
  long_desc="You're on the first floor in an exhibition room.\n";
  dest_dir=({
    "players/kelly/rooms/castle/tower21","east",
   });
  if(!present("sean o'connor")) 
  move_object(clone_object("players/kelly/monster/sean"),this_object()); 
}

