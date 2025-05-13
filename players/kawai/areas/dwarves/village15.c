inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead east-west, and "+
  "a small building stands to the north, although there is no entrance "+
  "on this side.  To the south is another building.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village14","west",
  "players/kawai/areas/dwarves/village13","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarf","An old dwarf opens up her window and throws a bucket of sewage out, just\n"+
  "missing your feet",
  "grocery","It is the usual grocery, probably specializing in dwarven food", 
  "house","You can't determine much about the house from out here",
  "building","Which one?  The north or south building?",
  "north building","It appears to be a grocery of some sort",
  "south building","It is a house, although you see no entrance here"});
  ::reset(arg);
  replace_program("room/room");}



