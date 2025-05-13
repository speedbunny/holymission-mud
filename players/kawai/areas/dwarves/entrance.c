inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Small passage";
  long_desc =
  "You are in a small underground passage.  To the south, the passage opens up "+
  "into a large, well lit cavern.  A small shaft leads down to the southeast.\n";
   smell = "The air is thick and dry..";
   dest_dir = ({"players/kawai/areas/dwarves/cavern","south",
   "players/kawai/areas/dwarves/shaft","southeast",
   "players/kawai/areas/darkpass","north"});
   items = ({"cave","It is small and barely lit",
   "passage","It is small and barely lit",
   "shaft","It is small and very steep.  You probably couldn't climb back up",
   "cavern","You can't see much from here"});
  ::reset(arg);
  replace_program("room/room");}




