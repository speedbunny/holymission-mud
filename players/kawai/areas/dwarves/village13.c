inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Intersection";
  long_desc = "You stand at an intersection in the Dwarf City.  Roads lead in "+
  "all directions.\n";
  smell = "The air fresh";
  dest_dir=({"players/kawai/areas/dwarves/village11","north",
  "players/kawai/areas/dwarves/village15","west",
  "players/kawai/areas/dwarves/village17","south",
  "players/kawai/areas/dwarves/village18","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "buildings","They all look alike in this section",
  "building","'Tis a little shack of rock and wood.."});
  ::reset(arg);
  replace_program("room/room");}
