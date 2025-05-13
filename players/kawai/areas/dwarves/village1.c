inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Intersection";
  long_desc = "You stand at an intersection in the Dwarf City.  Roads lead east-west "+
  "and south, while a small path leads back to the caves.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village2","west",
  "players/kawai/areas/dwarves/village3","east",
  "players/kawai/areas/dwarves/village4","south",
  "players/kawai/areas/dwarves/cavern","north"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty", 
  "city","You can only see the nearby buildings",
  "town","'Tis a lovely place",
  "caves","They are the caves that lead back to the surface",
  "buildings","You can't see much standing on the edge of the village",
  "building","'Tis a little shack of rock and wood..",
  "path","It leads back into the caves",
  "village","It is a lovely place, isn't it?"});
  ::reset(arg);
  replace_program("room/room");}


