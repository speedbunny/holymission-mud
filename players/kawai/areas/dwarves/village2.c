inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Not far to the north is the "+
  "cliff face, and to the south there is a small building, although there is "+
  "no entrance on this side.  Roads lead east-west.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village5","west",
  "players/kawai/areas/dwarves/village1","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "cliff","The rock is hard and smooth, and certainly to steep to climb",
  "face","The rock is hard and smooth, and certainly to steep to climb",
  "cliff face","The rock is hard and smooth, and certainly to steep to climb",  
  "rock","You aren't sure what kind it is",
  "road","It is dry and dusty",
  "village","It's such a quaint little town", 
  "town","It's a lovely place",
  "city","It's surprisingly quite today",
  "buildings","They all look the same here",               
  "building","It's just an ordinary building"});
  ::reset(arg);
  replace_program("room/room");}


