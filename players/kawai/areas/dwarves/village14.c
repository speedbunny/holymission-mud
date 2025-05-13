inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead north, south "+
  "and east.  Thick brush blocks entrance to the field to the west, "+
  "and a river can be seen some distance to the south.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village9","north",
  "players/kawai/areas/dwarves/village16","south",
  "players/kawai/areas/dwarves/village15","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "brush","The thick hedges block entrance to the field",
  "field","The wheat sways gently in the breeze",
  "wheat","Don't get out much, do you?",
  "hedge","It is thick and bushy",
  "hedges","They stretch far down the road",
  "dock","It is old, and creaks and bends in the rough water",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarf","Rats!  Just missed her...",
  "dwarves","The dwarves ignore you as they go about their business",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "river","It is swift and dangerous looking",
  "water","It flows by quickly",
  "building","It's just an ordinary building"});
  ::reset(arg);
  replace_program("room/room");}
