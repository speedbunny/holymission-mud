inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead north-south, and "+
  "a small building stands to the east.  Thick brush blocks entrance to the "+
  "field.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/empty1","east",
  "players/kawai/areas/dwarves/village5","north",
  "players/kawai/areas/dwarves/village7","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "brush","The thick hedges block entrance to the field",
  "field","The wheat sways gently in the breeze",
  "wheat","Don't get out much, do you?",
  "hedge","It is thick and bushy",
  "hedges","A tiny mole pokes its head out, then returns to the field",
  "mole","Awhh...how cute!",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "buildings","They all look alike in this section",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs down the street and hits you in the head with a rock",
  "building","It's just an ordinary building"});
  ::reset(arg);
  replace_program("room/room");}


