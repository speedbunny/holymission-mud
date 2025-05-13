inherit "room/room";
 
void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead north-south, and "+
  "a small building stands to the west, although there is no entrance "+
  "on this side.  To the east, a small shop is open for business.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/shop","east",
  "players/kawai/areas/dwarves/village1","north",
  "players/kawai/areas/dwarves/village10","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty.  This section looks heavily traveled", 
  "east building","It appears to be a shop",
  "west building","Seeing that there is no entrance, you have a hard time determining\n"+
  "what it is",
  "buildings","You are in a slightly more active section of the town.  As you look around\n"+
  "you occasionally see a dwarf walk on by, minding their own business",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "village","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","The dwarf city is busy with dwarves at work, and little ones at play",
  "building","Which one? The east building or west building?",
  "shop","It looks to be an equipment shop of some sort"});
  ::reset(arg);
  replace_program("room/room");}
