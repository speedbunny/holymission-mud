inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead north-south, and "+
  "a small building stands to the west, although there is no entrance "+
  "on this side.  To the east is a another small hut.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/empty2","east",
  "players/kawai/areas/dwarves/village10","north",
  "players/kawai/areas/dwarves/village13","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "buildings","They all look alike in this section",
  "hut","It looks to be some sort of celebration hall",
  "west building","Seeing no entrance, you can't determine the buildings nature",
  "east building","It looks like a festivities hall",
  "building","Which one?  The east building or west building?"});
  ::reset(arg);
  replace_program("room/room");}
