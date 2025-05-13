inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead north, and "+
  "a small building stands to the east, although there is no entrance "+
  "on this side.  Thick brush blocks entrance to the field to the west, "+
  "and a dock extends out into a river to the south.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village14","north",
  "players/kawai/areas/dwarves/dock","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "brush","The thick hedges block entrance to the field",
  "hedge","It is thick and bushy",
  "hedges","They stretch all the way down the road",
  "field","The field of wheat sways gently in the wind",
  "dock","It is old, and creaks and bends in the rough water",
  "river","It is swift and dangerous looking",
  "water","It flows by quickly",
  "wheat","Wheat.  A plant.  A grain.  You make bread out of it",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "road","It is dry and dusty",
  "dwarves","They pay no attention to you",
  "dwarf","Rats!  Just missed him...",
  "building","It's just an ordinary building"});
  ::reset(arg);
  replace_program("room/room");}


