inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City which leads into\n"+
  "a small alcove among the cliffs.  To cliff face is not far to "+
  "either north or south.  The road leads back to the main "+
  "part of town, and a small shack is against the cliff face "+
  "to the east.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village3","west",
  "players/kawai/areas/shack","east"});
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
  "alcove","You stand in a small cave like structure among the cliffs",
  "building","You can't tell much about the shack",
  "shack","You can't tell much about the shack",
  "cliffs","They tower high above you"});
  ::reset(arg);
  replace_program("room/room");}


