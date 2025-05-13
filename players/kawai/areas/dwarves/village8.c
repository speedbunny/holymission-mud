inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead east-west, and "+
  "a small building stands to the north, although there is no entrance "+
  "on this side.  To the south, a small shop is open for business.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/grocery","south",
  "players/kawai/areas/dwarves/village7","west",
  "players/kawai/areas/dwarves/village10","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "buildings","You are in a slightly more active section of the town.  As you look around\n"+
  "you occasionally see a dwarf walk on by, minding their own business",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "village","The dwarf city is busy with dwarves at work, and little ones at play",
  "road","It is heavily traveled",
  "town","The dwarf city is busy with dwarves at work, and little ones at play",
  "building","Which one?  The north building or south building?",
  "north building","Seeing no entrance on this side, you have a hard time determining\n"+
  "the nature of the building",
  "south building","It appears to be a shop of some sort",
  "shop","It looks to be a grocery of some sort"});
  ::reset(arg);
  replace_program("room/room");}
