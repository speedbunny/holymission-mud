inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Intersection";
  long_desc = "You stand at an intersection in the Dwarf City.  The cliff face "+
  "prevents all progress to the north, while roads lead to east "+
  "and south. A small path leads west towards a field.\n";
  smell = "The air fresh";
  dest_dir=({"players/kawai/areas/dwarves/fieldpath","west",
  "players/kawai/areas/dwarves/village2","east",
  "players/kawai/areas/dwarves/village6","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "brush","The thick hedges block entrance to the field",
  "field","The wheat sways gently in the breeze",
  "wheat","Don't get out much, do you?",
  "hedge","It is thick and bushy",
  "hedges","A tiny mole pokes its head out, then returns to the field",
  "mole","Awhh...how cute!",
  "path","It leads off into a giant wheat field",
  "cliff","It is steep and fairly smooth...probably unclimbable",
  "cliff face","It is steep and fairly smooth...probably unclimbable",
  "face","Just rock",
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
  "dwarf","A dwarf eyes you suspiciously, then leaves"});
  ::reset(arg);
  replace_program("room/room");}
