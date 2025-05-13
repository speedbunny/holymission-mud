inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Intersection";
  long_desc = "You stand at an intersection in the Dwarf City.  Thick brush "+
  "prevents all progress to the west, while roads lead to east "+
  "north, and south.\n";
  smell = "The air fresh";
  dest_dir=({"players/kawai/areas/dwarves/village6","north",
  "players/kawai/areas/dwarves/village8","east",
  "players/kawai/areas/dwarves/village9","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "brush","The thick hedges block entrance to the field",
  "field","The wheat sways gently in the breeze",
  "wheat","Don't get out much, do you?",
  "hedge","It is thick and bushy",
  "hedges","A tiny mole pokes its head out, then returns to the field",
  "mole","Awhh...how cute!",
  "buildings","They all look alike over here",
  "building","You see nothing special",
  "village","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","The dwarf city is busy with dwarves at work, and little ones at play",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","Rats!  Just missed her..."});
  ::reset(arg);
  replace_program("room/room");}
